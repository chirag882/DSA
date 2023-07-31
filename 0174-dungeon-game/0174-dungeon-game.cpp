class Solution {
public:
    int dp[205][205];
    int n,m;
    int rec(int i,int j,vector<vector<int>>& grid){
        // base
        if(i == n-1 && j == m-1){
            if(grid[i][j] < 0){
                int temp = (grid[i][j] * -1)+1;
                return temp;
            }else if(grid[i][j] >= 0){
                return 1;
            }
        }
        if(j >= m || i >= n || i < 0 || j < 0){
            return 1e9;
        }
        // cache 
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // compute
        int ans = 1e9;
        if(grid[i][j] < 0){
            ans = min(ans,min(rec(i+1,j,grid),rec(i,j+1,grid)) + abs(grid[i][j]));
        }else{
            int temp = min(rec(i+1,j,grid),rec(i,j+1,grid));
            if(grid[i][j] >= temp){
                ans = 1;
            }else{
                if(grid[i][j] == 0){
                    ans = min(ans,temp);
                }else{
                    ans = min(ans,temp - grid[i][j]);
                }
            }
        }
        // save n return
        return dp[i][j] = ans;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof(dp));
        n = dungeon.size();
        m = dungeon[0].size();
        return rec(0,0,dungeon);
    }
};