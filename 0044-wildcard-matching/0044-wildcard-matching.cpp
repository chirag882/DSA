class Solution {
public:
    int dp[2005][2005];
    // bool rec(int i,int j,string &s,string &t){
    //     // base
    //     if(i == 0 && j == 0){
    //         return true;
    //     }
    //     if(i > 0 && j == 0){
    //         return false;
    //     }
    //     if(i == 0 && j > 0){
    //         bool fl = true;
    //         int temp = j;
    //         while(temp){
    //             if(t[temp-1] == '*'){
    //                 temp--;
    //                 continue;
    //             }
    //             fl = false;
    //             break;
    //         }
    //         return fl;
    //     }
    //     // cache
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     // compute
    //     bool ans = false;
    //     if(s[i-1] == t[j-1] || t[j-1] == '?'){
    //         ans |= rec(i-1,j-1,s,t);
    //     }
    //     if(t[j-1] == '*'){
    //         // ans |= rec(i-1,j-1,s,t);
    //         ans |= rec(i-1,j,s,t);
    //         ans |= rec(i,j-1,s,t);
    //     }
    //     // save n return
    //     return dp[i][j] = ans;
    // }

    bool isMatch(string s, string t) {
        int n = s.size();
        int m = t.size();
        // memset(dp,-1,sizeof(dp));
        // return rec(n,m,s,t);
        vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        dp[0][0] = true; 
        for(int i=1;i<=n;i++){
            dp[i][0] = false;
        }
        for(int i=1;i<=m;i++){
            bool fl = true;
            for(int j=1;j<=i;j++){
                if(t[j-1] != '*'){
                    fl = false;
                    break;
                }
            }
            dp[0][i] = fl;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                bool ans = false;
                if(s[i-1] == t[j-1] || t[j-1] == '?'){
                    ans |= dp[i-1][j-1];
                }
                if(t[j-1] == '*'){
                    ans |= dp[i-1][j-1];
                    ans |= dp[i-1][j];
                    ans |= dp[i][j-1];
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][m];
    }
};