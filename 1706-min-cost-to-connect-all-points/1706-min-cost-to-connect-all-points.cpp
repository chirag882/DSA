class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> vis(n,false);
        vector<int> dist(n,INT_MAX);
        // cost vertex
        pq.push({0,0});
        dist[0] = 0;
        int ans = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cost = it.first;
            int edge = it.second;
            if(vis[edge]){
                continue;
            }
            // cout<<"h";
            ans += cost;
            vis[edge] = true;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int dis = abs(points[edge][0]-points[i][0])+abs(points[edge][1]-points[i][1]);
                    if(dist[i] > dis){
                        // cout<<"h";
                        dist[i] = dis;
                        pq.push({dis,i});
                    }
                }
            }
        }
        return ans;
    }
};