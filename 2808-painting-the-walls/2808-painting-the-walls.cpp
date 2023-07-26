class Solution {
public:
    // int dp[505][505];
    // int rec(int lvl,int remwal,vector<int>& cost, vector<int>& time){
    //     // base
    //     if(remwal <= 0){
    //         return 0;
    //     }
    //     if(lvl < 0){
    //         return 1e9;
    //     }
    //     // cache
    //     if(dp[lvl][remwal] != -1){
    //         return dp[lvl][remwal];
    //     }
    //     // compute
    //     int ans = 1e9;
    //     // take
    //     ans = min(ans,rec(lvl-1,remwal-time[lvl]-1,cost,time) + cost[lvl]);
    //     // not take
    //     ans = min(ans,rec(lvl-1,remwal,cost,time));
    //     // save n return
    //     return dp[lvl][remwal] = ans;
    // }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        // memset(dp,-1,sizeof(dp));
        int n = cost.size();
        // return rec(n-1,n,cost,time);
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int lvl=1;lvl<=n;lvl++){
            for(int remwal=1;remwal<=n;remwal++){
                int ans = 1e9;
                // take
                // if(remwal-time[lvl-1]-1 >= 0)
                ans = min(ans,dp[lvl-1][max(0,remwal-time[lvl-1]-1)] + cost[lvl-1]);
                // not take
                ans = min(ans,dp[lvl-1][remwal]);
                dp[lvl][remwal] = ans;
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<"\n";
        // }
        return dp[n][n];
    }
};