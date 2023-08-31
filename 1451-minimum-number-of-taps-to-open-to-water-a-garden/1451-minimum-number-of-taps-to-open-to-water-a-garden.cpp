class Solution {
public:
    int dp[10005];
    int m;
    int rec(int idx,vector<pair<int,int>> &v){
        // base
        if(v[idx].second == m){
            return 1;
        }
        if(idx == v.size()){
            return 1e9;
        }
        // cache
        if(dp[idx] != -1){
            return dp[idx]; 
        }
        // compute
        int ans = 1e9;
        for(int j=idx+1;j<v.size();j++){
            if(v[j].first > v[idx].second){
                break;
            }
            ans = min(ans,1+rec(j,v));
        }
        // save n return
        return dp[idx] = ans;
    }

    int minTaps(int mm, vector<int>& ranges) {
        m = mm;
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>> v;
        int n = ranges.size();
        for(int i=0;i<n;i++){
            int left = max(0,i-ranges[i]);
            int right = min(m,i+ranges[i]);
            v.push_back({left,right});
        }
        sort(v.begin(),v.end());
        int ans = 1e9;
        for(int i=0;i<n;i++){
            if(v[i].first == 0){
                ans = min(ans,rec(i,v));
            }
        }
        if(ans == 1e9)return -1;
        return ans;
    }
};