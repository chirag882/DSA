class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto it = pq.top();
            int effort = it[0];
            int x = it[1];
            int y = it[2];
            pq.pop();
            for(int k=0;k<4;k++){
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    int neweffort = max(effort,abs(heights[x][y] - heights[nx][ny]));
                    if(neweffort < dist[nx][ny]){
                        dist[nx][ny] = neweffort;
                        pq.push({neweffort,nx,ny});
                    }
                }
            }
        }        
        return dist[n-1][m-1];
    }
};