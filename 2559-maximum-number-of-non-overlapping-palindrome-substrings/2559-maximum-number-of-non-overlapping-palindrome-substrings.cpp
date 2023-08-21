class Solution {
public:
    vector<vector<bool>> isPalindrome(string& s){
        int n = s.size();
        vector<vector<bool>> memo(n, vector<bool>(n, false));
        
        for(int i=0; i<n; i++){
            memo[i][i] = true;
        }
        
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                memo[i][i+1] = true;
            }
        }
        
        int k = 2;
        
        while(k < n){
            int i=0;
            int j=k;
            
            while(j<n){
                if(s[i] == s[j] and memo[i+1][j-1]){
                    memo[i][j] = true;
                }
                
                i++;
                j++;
            }
            
            k++;
        }
        
        return memo;
    }
    int dp[2005];
    int k;
    int rec(int idx,string &s,vector<vector<bool>> &memo){
        // base
        if(idx == s.size()){
            return 0;
        }
        // cache check
        if(dp[idx] != -1){
            return dp[idx];
        }
        // compute
        int ans = 0;
        // not taking
        ans = max(ans,rec(idx+1,s,memo));
        // taking
        for(int j=idx+k;j<=s.size();j++){
            if(memo[idx][j-1]){
                ans = max(ans,1+rec(j,s,memo));
            }
        }
        // save n return
        return dp[idx] = ans;
    }

    int maxPalindromes(string s, int kk) {
        memset(dp,-1,sizeof(dp));
        k = kk;
        vector<vector<bool>> memo = isPalindrome(s);
        return rec(0,s,memo);
    }
};