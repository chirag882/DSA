class Solution {
public:

    int dp1[100005];
    int dp2[100005];
    
    int dfs(int node,int parent,vector<vector<pair<int,int>>> &g){
        int ans = 0;
        for(auto it : g[node]){
            if(it.first == parent)continue;
            ans += (dfs(it.first,node,g) + it.second);
        }
        return dp1[node] = ans;
    }

    void dfs2(int node,int parent,vector<vector<pair<int,int>>> &g){
        for(auto it : g[node]){
            if(it.first == parent)continue;
            dp2[it.first] =  (it.second^1) + dp2[node] - it.second;
            dfs2(it.first,node,g);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> g(n);
        for(auto it : edges){
            g[it[0]].push_back({it[1],0});
            g[it[1]].push_back({it[0],1});
        }
        dfs(0,-1,g);
        // for(int i=0;i<n;i++){
        //     cout<<dp1[i]<<" ";
        // }cout<<"\n";
        dp2[0] = dp1[0];
        dfs2(0,-1,g);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = dp2[i];
        }
        return ans;
    }
};