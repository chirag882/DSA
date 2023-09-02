class Solution {
public:
    int n;
    int dp[55];
    unordered_map<string,int> mp;
    int rec(int idx,string &s){
        // base
        if(idx == n){
            return 0;
        }
        // cache
        if(dp[idx] != -1){
            return dp[idx];
        }
        // compute
        int ans = 1e9;
        for(int i=idx;i<n;i++){
            string curr = s.substr(idx,i-idx+1);
            // cout<<curr<<"\n";
            if(mp.find(curr) != mp.end()){
                ans = min(ans,0+rec(i+1,s));
            }else{
                ans = min(ans,(int)curr.size()+rec(i+1,s));
            }
        }
        // save n return
        return dp[idx] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        memset(dp,-1,sizeof(dp));
        for(auto it : dictionary){
            mp[it]++;
        }
        return rec(0,s);
    }
};