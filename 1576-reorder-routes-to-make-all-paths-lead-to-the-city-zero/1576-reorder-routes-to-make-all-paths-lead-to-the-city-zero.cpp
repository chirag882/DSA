class Solution {
public:

    int ans = 0;

    void dfs(int node,int parent,vector<vector<pair<int,int>>> &g){
        for(auto it : g[node]){
            if(it.first == parent)continue;
            if(it.second){
                ans++;
            }
            dfs(it.first,node,g);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> g(n);
        for(auto it : connections){
            g[it[0]].push_back({it[1],1});
            g[it[1]].push_back({it[0],0});
        }
        dfs(0,-1,g);
        return ans;
    }
};