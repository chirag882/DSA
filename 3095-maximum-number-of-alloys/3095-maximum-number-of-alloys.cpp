class Solution {
public:
    int n,b;
    bool check(int k,int mid,vector<vector<int>> &composition, vector<int>& cost, vector<int>& stock){
        long long sum = 0;
        for(int i=0;i<n;i++){
            long long temp = composition[k][i] * 1ll * mid; 
            if(temp > stock[i]){
                sum +=  ((temp - stock[i])*1ll*(cost[i]));
            }else{
                continue;
            }
        }
        if(sum <= b){
            return true;
        }
        return false;
    }
    
    int maxNumberOfAlloys(int nn, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        n = nn;
        b = budget;
        int ans = 0;
        for(int i=0;i<k;i++){
            int l = 0,r = 1e9;
            int curr = -1;
            while(l <= r){
                int mid = (l+r)/2;
                if(check(i,mid,composition,cost,stock)){
                    l = mid+1;
                    curr = mid;
                }else{
                    r = mid-1;
                }
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};