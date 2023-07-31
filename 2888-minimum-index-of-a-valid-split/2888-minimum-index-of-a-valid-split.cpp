class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int dominant = -1;
        for (auto& x : freq) {
            if (x.second * 2 > n) {
                dominant = x.first;
                break;
            }
        }
        if(2*freq[dominant] == n+1){
            return -1;
        }
        int cnt = 0;
        int idx = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == dominant){
                cnt++;
            }
            if(2*cnt > (i+1)){
                idx = i;
                break;
            }
            // cout<<cnt<<"\n";
        }
        return idx;

    }
};