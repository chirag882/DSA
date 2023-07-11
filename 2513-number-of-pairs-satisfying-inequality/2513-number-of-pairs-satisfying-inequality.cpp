typedef long long ll;   
const int offset = 2E4;

class Solution {
private : 
    ll maxN;
    vector<ll> st;

    ll merge(ll &a,ll &b){
        return a+b;
    }

    ll query(int idx,ll l,ll r,ll i,ll j){
        if(i > r || j < l){
            return 0;
        }
        if(i <= l && j >= r){
            return st[idx];
        }
        ll mid = (r+l)>>1;
        ll lll = query(idx<<1,l,mid,i,j);
        ll rr = query(idx<<1|1,mid+1,r,i,j);
        return lll+rr;
    }

    void update(int idx,ll l,ll r,ll val){
        if(l == r){
            st[idx]++;
            return;
        }
        ll mid = (r+l)>>1;
        if(val <= mid){
            update(idx<<1,l,mid,val);    
        }else{
            update(idx<<1|1,mid+1,r,val);
        }
        st[idx] = merge(st[idx<<1] , st[idx<<1|1]);
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<ll> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = nums1[i] - nums2[i] + offset;
        }
        maxN = 2 * offset + 1;
        st.resize(maxN * 4 + 10, 0);
        ll ans = 0;
        for(auto it : v) {
            ans += query(1, 0, maxN - 1, 0, it + diff);
            update(1, 0, maxN - 1, it);
        }
        return ans;
    }
};