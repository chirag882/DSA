typedef long long int ll;
const int BITS = 34;
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& rec, long long k) {
        int n = rec.size();
        vector<vector<ll>> dist(BITS,vector<ll>(n));
        vector<vector<ll>> sum(BITS,vector<ll>(n));
        for(int i=0;i<n;i++){
            dist[0][i] = rec[i];
            sum[0][i] = rec[i]+i;
        }
        for(int i=1;i<BITS;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = dist[i-1][dist[i-1][j]];
                sum[i][j] = sum[i-1][j] + sum[i-1][dist[i-1][j]] - dist[i-1][j];
            }
        } 
        vector<ll> final_dist(n),final_sum(n);
        for(int i=0;i<n;i++){
            final_dist[i] = i;
            final_sum[i] = i;
        }
        for(int i=BITS-1;i>=0;i--){
            if(((1ll<<i) & k) == 0)continue;
            for(int j=0;j<n;j++){
                final_sum[j] = sum[i][final_dist[j]] + final_sum[j] - final_dist[j];
                final_dist[j] = dist[i][final_dist[j]];
            }
        }
        ll ans = 0;
        for(auto it : final_sum){
            ans = max(it,ans);
        }
        return ans;
    }
};