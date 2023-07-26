class Solution {
public:
    int n;
    vector<vector<vector<vector<int>>>> dp;
    int rec(int x1,int y1,int x2,int y2,vector<vector<int>> &grid){
        // base
        if(x1 == n-1 && y1 == n-1){
            return grid[x1][y1];
        }
        // cache
        if(dp[x1][y1][x2][y2] != -1){
            return dp[x1][y1][x2][y2];
        }
        // compute
        int ans = -1e9;
        int curr = 0;
        if(x1 == x2 && y1 == y2){
            curr += grid[x1][y1];
        }else{
            curr += grid[x1][y1] + grid[x2][y2];
        }
        // down down
        if(x1 + 1 < n && x2 + 1 < n && grid[x1+1][y1] != -1 && grid[x2+1][y2] != -1){
            ans = max(ans,curr+rec(x1+1,y1,x2+1,y2,grid));
        }
        // down right
        if(x1 + 1 < n && y2 + 1 < n && grid[x1+1][y1] != -1 && grid[x2][y2+1] != -1){
            ans = max(ans,curr+rec(x1+1,y1,x2,y2+1,grid));
        }
        // right down
        if(y1 + 1 < n && x2 + 1 < n && grid[x1][y1+1] != -1 && grid[x2+1][y2] != -1){
            ans = max(ans,curr+rec(x1,y1+1,x2+1,y2,grid));
        }
        // right right
        if(y1 + 1 < n && y2 + 1 < n && grid[x1][y1+1] != -1 && grid[x2][y2+1] != -1){
            ans = max(ans,curr+rec(x1,y1+1,x2,y2+1,grid));
        }
        // save n return
        return dp[x1][y1][x2][y2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        return max(0,rec(0,0,0,0,grid));
    }
};