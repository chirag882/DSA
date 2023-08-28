class Solution {
public:
    int dp[1001];
    int n;
    int rec(int idx,vector<vector<int>> &pair){
        // base
        if(idx == n){
            return 0;
        }
        // cache
        if(dp[idx] != -1){
            return dp[idx]; 
        }
        // compute
        int ans = 1;
        // take
        for(int i=idx+1;i<n;i++){
            if(pair[idx][1] < pair[i][0]){
                ans = max(ans,1+rec(i,pair));
            }
        }
        // not take
        ans = max(ans,rec(idx+1,pair));
        // save n return
        return dp[idx] = ans;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
        n = pairs.size();
        return rec(0,pairs);
    }
};