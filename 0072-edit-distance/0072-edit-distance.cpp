class Solution {
public:
    // int dp[505][505];
    // int rec(int i,int j,string &s,string &t){
    //     // base
    //     if(i == 0){
    //         return j;
    //     }
    //     if(j == 0){
    //         return i;
    //     }
    //     // cache
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     // compute
    //     int ans = 1e9;
    //     if(s[i-1] == t[j-1]){
    //         ans = min(ans,rec(i-1,j-1,s,t));
    //     }else{
    //         // remove 
    //         ans = min(ans,1+rec(i-1,j,s,t));
    //         // insert
    //         ans = min(ans,1+rec(i,j-1,s,t));
    //         // replace
    //         ans = min(ans,1+rec(i-1,j-1,s,t));
    //     }
    //     // save n return
    //     return dp[i][j] = ans;
    // }

    int minDistance(string s, string t) {
        // memset(dp,-1,sizeof(dp));
        int n = s.size();
        int m = t.size();
        // return rec(n,m,s,t);

        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            dp[i][0] = i;
        }   
        for(int i=0;i<=m;i++){
            dp[0][i] = i;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ans = 1e9;
                if(s[i-1] == t[j-1]){
                    ans = min(ans,dp[i-1][j-1]);
                }else{
                    // remove 
                    ans = min(ans,1+dp[i-1][j]);
                    // insert
                    ans = min(ans,1+dp[i][j-1]);
                    // replace
                    ans = min(ans,1+dp[i-1][j-1]);
                }
                // save n return
                dp[i][j] = ans;
            }
        }

        return dp[n][m];

    }
};