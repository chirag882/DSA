class Solution {
public:
    int dp[505][505];
    int rec(int i,int j,string &s,string &t){
        // base
        if(i == 0){
            return j;
        }
        if(j == 0){
            return i;
        }
        // cache
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // compute
        int ans = 1e9;
        if(s[i-1] == t[j-1]){
            ans = min(ans,rec(i-1,j-1,s,t));
        }else{
            // remove 
            ans = min(ans,1+rec(i-1,j,s,t));
            // insert
            ans = min(ans,1+rec(i,j-1,s,t));
            // replace
            ans = min(ans,1+rec(i-1,j-1,s,t));
        }
        // save n return
        return dp[i][j] = ans;
    }

    int minDistance(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        int m = t.size();
        return rec(n,m,s,t);
    }
};