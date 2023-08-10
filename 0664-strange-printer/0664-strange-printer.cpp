class Solution {
public:
    int dp[105][105];
    int n;
    int rec(int i,int j,string &s){
        // base
        if(i == j){
            return 1;
        }
        if(i+1 == j){
            if(s[i] == s[j]){
                return 1;
            }
            return 2;
        }
        // cache
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // compute
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            int curr = rec(i,k,s)+rec(k+1,j,s);
            if(s[i] == s[j]){
                curr--;
            }
            ans = min(ans,curr);
        }
        // save n return
        return dp[i][j] = ans;
    }
    
    int strangePrinter(string s) {
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,n-1,s);
    }
};