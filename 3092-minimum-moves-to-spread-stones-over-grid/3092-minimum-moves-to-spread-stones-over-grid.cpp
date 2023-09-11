class Solution {
public:
    vector<vector<int>> dp;
    int all_set;
    int n,m;

    int cost(int x,int y,vector<pair<int,int>> &need,int bs){
        int ans = 0;
        for(int i=0;i<m;i++){
            if((1<<i) & bs){
                ans += (abs(need[i].first - x) + abs(need[i].second - y));
            }
        }
        return ans;
    }

    int rec(int i,int mask,vector<vector<int>> &has,vector<pair<int,int>> &need){
        // base
        if(mask == all_set){
            return 0;
        }
        if(i == n){
            return 1e9;
        }
        // cache
        if(dp[i][mask] != -1){
            return dp[i][mask];
        }
        // compute
        int ans = 1e9;
        for(int bs=1;bs<=all_set;bs++){
            if((bs & mask) == 0 && __builtin_popcount(bs) <= has[i][2]){
                ans = min(ans,rec(i+1,mask|bs,has,need) + cost(has[i][0],has[i][1],need,bs));
            }
        }
        // save n return
        return dp[i][mask] = ans;
    }

    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>> has;
        vector<pair<int,int>> need;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j] == 0){
                    need.push_back({i,j});
                }else if(grid[i][j] > 1){
                    has.push_back({i,j,grid[i][j]-1});
                }
            }
        }
        m = need.size();
        n = has.size();
        all_set = (1<<m)-1;
        dp.resize(n,vector<int>(all_set+1,-1));
        return rec(0,0,has,need);
    }   
};