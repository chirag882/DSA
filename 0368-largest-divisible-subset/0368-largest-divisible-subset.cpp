class Solution {
public:
    // int dp[1001][1001];
    // int rec(int i,int prev,vector<int> &nums){
    //     // base
    //     if(i == nums.size()){
    //         return 0;
    //     }
    //     // cache
    //     if(dp[i][prev+1] != -1){
    //         return dp[i][prev+1];
    //     }
    //     // compute
    //     // take
    //     int ans = 0;
    //     if((prev == -1 ) || (nums[i] % nums[prev] == 0)){
    //         ans = max(ans,1 + rec(i+1,i,nums));
    //     }
    //     // not take
    //     ans = max(ans,rec(i+1,prev,nums));
    //     // save n return
    //     return dp[i][prev+1] = ans;
    // }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
        // int n = nums.size();
        sort(nums.begin(),nums.end());
        // cout<<rec(0,-1,nums)<<"\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<"\n";
        // }
        // return {};
        int n = nums.size();
        vector<int> dp(n,1),hash(n);
        int li;
        int maxi = 0;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                li = i;
            }
        }
        vector<int> res(maxi);
        res[0] = nums[li];
        int i = 1;
        while(hash[li] != li){
            res[i++] = nums[hash[li]];
            li = hash[li];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};