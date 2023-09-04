const int N = 10005;
const int W = 27;
vector<vector<int>> up(15,vector<int>(N,0));
vector<vector<pair<int,int>>> v(N);
vector<int> lvl(N,0);
vector<vector<int>> freq(N,vector<int>(W,0));
class Solution {
public:
    void Reset() {
        for (auto &i: lvl) i = 0;
        for (auto &i: up) 
            for (auto &j: i) j = 0;
        for (auto &i: v)
            i.clear();
    }

    void dfs(int node,int par){
        lvl[node] = lvl[par] + 1;
        up[0][node] = par;
        for(int i=1;i<15;i++){
            up[i][node] = up[i-1][up[i-1][node]];
        }
        for(auto it : v[node]){
            int nextnode = it.first;
            int weight = it.second;
            if(nextnode == par)continue;
            freq[nextnode] = freq[node];
            freq[nextnode][weight]++;
            dfs(nextnode,node);
        }

    }

    int lca(int a,int b){
        if(lvl[b] > lvl[a])swap(a,b);
        int diff = lvl[a]-lvl[b];
        for(int i=14;i>=0;i--){
            if((1<<i) & diff){
                a = up[i][a];
            }
        }
        if (a == b) return a;
        for(int i=14;i>=0;i--){
            if(up[i][a] != up[i][b]){
                a = up[i][a];
                b = up[i][b];
            }
        }
        return up[0][a];
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        Reset();
        for(auto it : edges){
            v[it[0]+1].push_back({it[1]+1,it[2]});
            v[it[1]+1].push_back({it[0]+1,it[2]});
        }
        vector<int> fans;
        dfs(1,0);
        for(int i=0;i<q.size();i++){
            int a = q[i][0]+1;
            int b = q[i][1]+1;
            int lc = lca(a,b);
            vector<int> freqtemp(27);
            for(int i=0;i<27;i++){
                freqtemp[i] = freq[a][i] + freq[b][i] - 2*freq[lc][i];  
            }
            int mx = 0, sum = 0;
            for (auto i : freqtemp) {
                mx = max(mx, i);
                sum += i;
            }
            fans.push_back(sum - mx);
        }
        return fans;
    }
};