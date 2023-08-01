class Solution {
public:
    int res = 0;
    void dfs(int node,int time,int score,vector<int>& vis,vector<int>& val, vector<pair<int,int>> adj[], int T){
        if(time > T){
            return; 
        }
        if(vis[node] == 0){
            score += val[node];
        }  
        if(node == 0){
            res = max(res,score);
        }
        vis[node]++;
        for(auto it : adj[node]){
            int neg = it.first;
            int tt = it.second;
            dfs(neg,time + tt,score,vis,val,adj,T);
        }
        vis[node]--;
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<pair<int,int>> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> vis(n,0);
        dfs(0,0,0,vis,values,adj,maxTime);
        return res;
    }
};