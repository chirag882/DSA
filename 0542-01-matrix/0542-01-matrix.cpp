class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newx = it.first + dx[i];
                int newy = it.second + dy[i];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m && ans[newx][newy] > 1 + ans[it.first][it.second]){
                    ans[newx][newy] = 1 + ans[it.first][it.second];
                    q.push({newx,newy});
                }
            }
        }
        return ans;
    }
};