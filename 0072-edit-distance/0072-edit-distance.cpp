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

        // vector<vector<int>> dp(n+1,vector<int>(m+1));
        vector<int> prev(m+1),curr(m+1);
        for(int i=0;i<=m;i++){
            prev[i] = i;
        }

        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){
                int ans = 1e9;
                if(s[i-1] == t[j-1]){
                    ans = min(ans,prev[j-1]);
                }else{
                    // remove 
                    ans = min(ans,1+prev[j]);
                    // insert
                    ans = min(ans,1+curr[j-1]);
                    // replace
                    ans = min(ans,1+prev[j-1]);
                }
                // save n return
                curr[j] = ans;
            }
            prev = curr;
        }

        return prev[m];

    }
};