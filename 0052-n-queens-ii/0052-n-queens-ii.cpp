class Solution {
public:

    bool isValid(int r,int c,vector<vector<int>> &grid){
        bool fl = true;
        // diagonal
        int tempr = r,tempc = c;
        while(tempr >= 0 && tempc >= 0){
            if(grid[tempr][tempc] == 1){
                return false;
            }
            tempr--;tempc--;
        }
        tempr = r,tempc = c;
        while(tempr >= 0 && tempc < grid.size()){
            if(grid[tempr][tempc] == 1){
                return false;
            }
            tempr--;tempc++;
        }
        tempr = r,tempc = c;
        // vertical
        while(tempr >= 0){
            if(grid[tempr][c] == 1){
                return false;
            }
            tempr--;
        }
        // horizontal
        while(tempc >= 0){
            if(grid[r][tempc] == 1){
                return false;
            }
            tempc--;
        }
        return true;
    }

    int rec(int i,int j,vector<vector<int>> &grid){
        // base
        if(i == grid.size()){
            return 1;
        }
        // compute
        int ans = 0;
        for(int k=j;k<grid.size();k++){
            if(isValid(i,k,grid)){
                grid[i][k] = 1;
                ans += rec(i+1,0,grid);
                grid[i][k] = 0;
            }
        }
        return ans;
    }

    int totalNQueens(int n) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        return rec(0,0,grid);
    }
};