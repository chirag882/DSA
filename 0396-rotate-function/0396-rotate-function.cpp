class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int tot = 0;
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
            tot += (nums[i]*i);
        } 
        int ans = tot;
        for(int i=n-1;i>=0;i--){
            tot = tot - (nums[i]*(n-1)) + (sum-nums[i]);
            ans = max(ans,tot);
        }
        return ans;
    }
};