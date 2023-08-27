class Solution {
public:
    int dp[2000][2000];
    int rec(int idx,int prev,vector<int> &stones,map<int,int> &s){
        // base
        if(idx == stones.size()-1){
            return 1;
        }
        if(idx > stones.size()){
            return 0;
        }
        // cache check
        if(dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        // compute
        int ans = 0;
        // k-1
        if(prev  > 1 && s.find(stones[idx]+prev-1) != s.end()){
            ans = max(ans,rec(s[stones[idx]+prev-1],prev-1,stones,s));
        }
        // k
        if(s.find(stones[idx]+prev) != s.end()){
            ans = max(ans,rec(s[stones[idx]+prev],prev,stones,s));
        }
        // k+1
        if(s.find(stones[idx]+prev+1) != s.end()){
            ans = max(ans,rec(s[stones[idx]+prev+1],prev+1,stones,s));
        }
        // save n return
        return dp[idx][prev] = ans;
    }

    bool canCross(vector<int>& stones) {
        if(stones[1] != 1){
            return false;
        }
        memset(dp,-1,sizeof(dp));
        map<int,int> mp;
        for (int i = 0; i < stones.size(); i++) {
            mp[stones[i]] = i;
        }
        return rec(1,1,stones,mp);
    }
};