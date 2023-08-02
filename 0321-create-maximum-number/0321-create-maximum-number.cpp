class Solution {
public:

    vector<int> maxlen(vector<int> &v,int k){
        vector<int> res;
        int n = v.size();
        for(int i=0;i<n;i++){
            while(!res.empty() && v[i] > res.back() &&  k-res.size() < n-i ){
                res.pop_back();
            }
            if(res.size() < k){
                res.push_back(v[i]);
            }
        }
        return res;
    }

    bool greater(vector<int> &n1,vector<int> &n2,int a,int b){
        while(a < n1.size() || b < n2.size()){
            if(a == n1.size()){
                return false;
            }else if(b == n2.size()){
                return true;
            }else if(n1[a] < n2[b]){
                return false;
            }else if(n1[a] > n2[b]){
                return true;
            }else{
                a++;
                b++;
            }
        }
        return true;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        for(int i=0;i<=n && i<=k;i++){
            int j=k-i;
            if(j > m)continue;
            vector<int> n1 = maxlen(nums1,i);
            vector<int> n2 = maxlen(nums2,j);
            vector<int> merged;
            int a = 0;
            int b = 0;
            while(a < n1.size() || b < n2.size()){
                if(a == n1.size()){
                    merged.push_back(n2[b++]);
                }else if(b == n2.size()){
                    merged.push_back(n1[a++]);
                }else if(n1[a] < n2[b]){
                    merged.push_back(n2[b++]);
                }else if(n1[a] > n2[b]){
                    merged.push_back(n1[a++]);
                }else{
                    if(greater(n1,n2,a,b)){
                        merged.push_back(n1[a++]);
                    }else{
                        merged.push_back(n2[b++]);
                    }
                }
            }
            if(merged > ans){
                ans = merged;
            }
        }
        return ans;
    }
};