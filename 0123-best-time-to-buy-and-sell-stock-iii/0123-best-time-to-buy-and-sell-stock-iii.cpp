class Solution {
public:
    int dp[100005][3][2];
    int n;
    int rec(int idx,int limit,int k,vector<int>& prices){
        // base
        if(idx == n){
            return 0;
        }
        // cache
        if(dp[idx][limit][k] != -1){
            return dp[idx][limit][k];
        }
        // compute
        int ans = 0;
        // buy
        if(limit < 2){
            ans = max(ans,-prices[idx] + rec(idx+1,limit+1,1,prices));
        }
        // not buy 
        ans = max(ans,rec(idx+1,limit,k,prices));
        // sell
        if(k == 1){
            ans = max(ans,rec(idx+1,limit,0,prices) + prices[idx]);
        }
        // save n return
        return dp[idx][limit][k] = ans;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,prices);
    }
};