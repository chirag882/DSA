class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idx, int val) {
        int n = nums.size();
        vector<int> pref_max(n),pref_min(n),suff_max(n),suff_min(n);
        pref_max[0] = 0;
        pref_min[0] = 0;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[pref_max[i-1]]){
                pref_max[i] = i;
            }else{
                pref_max[i] = pref_max[i-1];
            }
            if(nums[i] < nums[pref_min[i-1]]){
                pref_min[i] = i;
            }else{
                pref_min[i] = pref_min[i-1];
            }
        }
        suff_max[n-1] = n-1;
        suff_min[n-1] = n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] > nums[suff_max[i+1]]){
                suff_max[i] = i;
            }else{
                suff_max[i] = suff_max[i+1];
            }
            if(nums[i] < nums[suff_min[i+1]]){
                suff_min[i] = i;
            }else{
                suff_min[i] = suff_min[i+1];
            }
        }
        for(int i=0;i<n;i++){
            if(i + idx < n){
                if(abs(nums[pref_max[i]] - nums[suff_min[i+idx]]) >= val){
                    return {i,suff_min[i+idx]};
                }else if((abs(nums[pref_min[i]] - nums[suff_max[i+idx]]) >= val)){
                    return {i,suff_max[i+idx]};
                } 
            }       
        }
        return {-1,-1};
    }
};