// Question : https://leetcode.com/problems/rotting-oranges/description/

// Solution
class Solution {
public:

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int n,m;
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> rotten;
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int tot1 = 0;
        int tot2 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    tot1++;
                }
                if(grid[i][j] == 0){
                    tot2++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int cnt = 0;
        int sz = 0;
        while(!q.empty()){
            int o = q.size();
            cnt++;
            while(o--){
                auto it = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int newx = it.first + dx[k];
                    int newy = it.second + dy[k];
                    if(newx < 0 || newx >= n || newy >= m || newy < 0 || grid[newx][newy] == 2 || 
                    grid[newx][newy] == 0 || vis[newx][newy] == 1)continue;
                    q.push({newx,newy});
                    sz++;
                    vis[newx][newy] = 1;
                }
            }
        }
        if(tot1 != sz)return -1;
        return (cnt == 0) ? 0 : cnt-1;
    }
};