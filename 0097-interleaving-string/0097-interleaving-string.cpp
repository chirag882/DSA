class Solution {
public:
    int n,m;
    int dp[105][105];
    int rec(int i,int j,int k,string &s1,string &s2,string &s3){
        // base
        if(k >= s3.size()) 
            return 1;
        if(i >= n && j >= m)
            return 0;
        // cache
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // compute
        int ans = 0;
        // taking first
        if(i != n && s1[i] == s3[k])
            ans = max(ans,rec(i+1,j,k+1,s1,s2,s3));
        // taking second
        if(j != m && s2[j] == s3[k])
            ans = max(ans,rec(i,j+1,k+1,s1,s2,s3));
        // save n return
        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        if(s3.size() != n+m){
            return false;
        }
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,s1,s2,s3);
    }
};