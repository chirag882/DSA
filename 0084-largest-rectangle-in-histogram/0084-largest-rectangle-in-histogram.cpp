class Solution {
public:
    vector<int> st;
    vector<int> v;
    int n;
    int merge(int i,int j){
        if(i==-1)return j;
        if(j==-1)return i;
        if(v[i] < v[j]){
            return i;
        }
        return j;
    }
    void build(int idx,int l,int r){
        if(l == r){
            st[idx] = l;
            return;
        }
        int mid = (l+r)/2;
        build(idx<<1,l,mid);
        build(idx<<1|1,mid+1,r);
        st[idx] = merge(st[idx<<1],st[idx<<1|1]);
    }
    int query(int idx,int l,int r,int ql,int qr){
        // cout<<r<<"--\n";
        if(r < ql || l > qr){
            // cout<<r<<"--\n";
            // cout<<"h0"<<"\n";
            return -1;
        }
        if(ql <= l && r <= qr){
            return st[idx];
        }
        // cout<<l<<" "<<r<<"\n";
        int mid = (l+r)/2;
        int left = query(idx<<1,l,mid,ql,qr);
        int right = query(idx<<1|1,mid+1,r,ql,qr);
        return merge(left,right);
    }
    int rec(int l,int r,vector<int> &v){
        if (l > r)  return INT_MIN;
        if (l == r)  return v[l];
        // cout<<r<<"--\n";
        // cout<<n-1<<"\n";
        int idx = query(1,0,n-1,l,r);
        // cout<<idx<<"\n";
        if(idx != -1){
            return max({rec(l,idx-1,v),rec(idx+1,r,v),v[idx]*(r-l+1)});
        }
        return INT_MIN;
    }
    int largestRectangleArea(vector<int>& h) {
        n = h.size();
        v.resize(n);
        for(int i=0;i<n;i++){
            v[i] = h[i];
        }
        int size = 4*n;
        st.resize(size);
        build(1,0,n-1);
        return rec(0,n-1,h);
    }
};