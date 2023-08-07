class Solution {
public:
    int n,m;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool isvalid(int i,int j){
        if(i < n && i >= 0 && j < m && j >= 0){
            return true;
        }
        return false;
    }
    bool ischk(int val,vector<vector<int>>& grid,vector<vector<int>>& maxdistance){
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vis[0][0] = true;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newx = it.first + dx[i];
                int newy = it.second + dy[i];
                if(isvalid(newx,newy) && !vis[newx][newy] && maxdistance[newx][newy] >= val){
                    if(newx == n-1 && newy == m-1){
                        return true;
                    }
                    vis[newx][newy] = true;
                    q.push({newx,newy});
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        queue<vector<int>> q;
        n=grid.size();
        m=grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1){
            return 0;
        }
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    q.push({i,j,0});
                    vis[i][j] = true;
                }
            }
        }
        vector<vector<int>> maxdistance(n,vector<int>(m,0));
        auto it = q.front();
        while(!q.empty()){
            int sz = q.size();
            // cout<<"size"<<sz<<"\n";
            while(sz--){
                auto it = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int newx = it[0] + dx[i];
                    int newy = it[1] + dy[i];
                    int distance = it[2];
                    if(isvalid(newx,newy) && !vis[newx][newy] && grid[newx][newy] != -1){
                        vis[newx][newy] = true;
                        maxdistance[newx][newy] = distance + 1;
                        q.push({newx,newy,distance+1});
                    }
                }
            }
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<m;j++){
            //         cout<<maxdistance[i][j]<<" ";
            //     }cout<<"\n";
            // }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<maxdistance[i][j]<<" ";
        //     }cout<<"\n";
        // }
        int x = min(maxdistance[0][0],maxdistance[n-1][m-1]);
        int l = 0;
        int r = x;
        // cout<<l<<' '<<r<<"\n";
        int ans = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(ischk(mid,grid,maxdistance)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
};