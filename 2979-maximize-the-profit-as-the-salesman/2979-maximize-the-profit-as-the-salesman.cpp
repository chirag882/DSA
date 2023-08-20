class Solution {
public:
    int dp[100005];
    int rec(int idx,vector<vector<int>>& v){
        // base
        if(idx == v.size()){
            return 0;
        }
        // cache
        if(dp[idx] != -1){
            return dp[idx];
        } 
        // compute
        int ans = INT_MIN;
        // take
        int newidx = v.size();
        int l = idx+1,r = v.size()-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(v[mid][0] > v[idx][1]){
                newidx = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        ans = max(ans,rec(newidx,v) + v[idx][2]);    
        // not take
        ans = max(ans,rec(idx+1,v));
        // save n return
        return dp[idx] = ans;
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& o) {
        memset(dp,-1,sizeof(dp));
        sort(o.begin(),o.end());
        return rec(0,o);
    }
};