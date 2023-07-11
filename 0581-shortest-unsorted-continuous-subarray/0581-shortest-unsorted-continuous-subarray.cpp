class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        int ans = 0;
        int n = nums.size();
        int l=n,r=0;
        for(int i=0;i<n;i++){
            if(temp[i] == nums[i]){
                continue;
            }else{
                l = min(l,i);
                r = max(r,i);
            }
        }
        if(r < l){
            return 0;
        }
        return r-l+1;
    }
};