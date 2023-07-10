class Solution {
public:
    
    vector<int> parent;
    vector<int> dist;
    int n;
    void dfs(int node,int par,vector<vector<int>> &adj,int currdist){
        parent[node] = par;
        dist[node] = currdist;
        for(auto it : adj[node]){
            if(it == par)continue;
            dfs(it,node,adj,currdist + 1);
        }
    }
    // void dfs2(int node,int par,vector<vector<int>> &adj,vector<int> &amount){
    //     dp[node] = amount[node];
    //     int child = INT_MIN;
    //     for(auto it : adj[node]){
    //         if(it == par)continue;
    //         dfs2(it,node,adj,amount);
    //         // child = max(dfs2(it,par,adj,amount),child);
    //         child = max(dp[it],child);
    //     }
    //     if(child != INT_MIN)
    //         dp[node] += child;
    // }
    vector<int> dp;
    int dfs2(int node,int par,vector<vector<int>> &adj,vector<int> &amount,vector<int> &dp){
        // base
        
        // cache
        if(dp[node] != -1){
            return dp[node];
        }
        // compute
        int ans = -1e9;
        for(auto it : adj[node]){
            if(it == par)continue;
            ans = max(ans,amount[node] + dfs2(it,node,adj,amount,dp));
        }
        // save n return
        if(ans == -1e9){
            return dp[node] = amount[node];
        }else{
            return dp[node] = ans;
        }
    }

    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        n = amount.size(); 
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        parent.resize(n,0);
        dist.resize(n,0);
        dp.resize(n,-1);
        dfs(0,-1,adj,0);
        int cur = 0;
        while(bob != 0){
            if(dist[bob] > cur){
               amount[bob] = 0; 
            }else if(dist[bob] == cur){
                amount[bob]/=2;
            }
            cur++;
            bob = parent[bob];
        }
        return dfs2(0,-1,adj,amount,dp);
        // return dp[0];
    }
};