class Solution {
public:

    int dp[101][101];
    int countPaths(int i, int j, int n, int m){
        if(i==n-1 && j==m-1){
            return 1;
        }

        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        else{
            return dp[i][j] = countPaths(i+1, j, n, m) + countPaths(i, j+1, n, m);
        }
    }
    
    
    int uniquePaths(int m, int n) {
        // memset(dp,0,sizeof(dp));
        return countPaths(0,0,m,n);
    }
};