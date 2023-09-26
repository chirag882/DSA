class Solution {
public:
    int n;
    int dp[30005][2];
    int rec(int idx,int k,vector<int>& prices){
        // base
        if(idx == n){
            return 0;
        }
        // cache
        if(dp[idx][k] != -1){
            return dp[idx][k];
        }
        // compute
        int ans = 0;
        // buy
        ans = max(ans,-prices[idx] + rec(idx+1,1,prices));
        // not buy 
        ans = max(ans,rec(idx+1,k,prices));
        // sell
        if(k == 1){
            ans = max(ans,rec(idx+1,0,prices) + prices[idx]);
        }
        // save n return
        return dp[idx][k] = ans;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,prices);
    }
};