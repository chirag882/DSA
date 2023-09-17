class Solution {
public:

    struct Node{
        int mask,dist,node;    
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        queue<Node> q;
        int n = graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto it : graph[i]){
                adj[i].push_back(it);
                adj[it].push_back(i);
            }
        }
        vector<vector<int>> vis(1<<n,vector<int>(n));
        for(int i=0;i<n;i++){
            q.push({1<<i,0,i});
            vis[1<<i][i] = true;
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it.mask == (1<<n)-1){
                return it.dist;
            }
            for(auto nextnode : adj[it.node]){
                int newmask = it.mask | (1<<nextnode);
                if(vis[newmask][nextnode]){
                    continue;
                }
                q.push({newmask,it.dist+1,nextnode});
                vis[newmask][nextnode] = true;
            }
        }
        return -1;
    }
};