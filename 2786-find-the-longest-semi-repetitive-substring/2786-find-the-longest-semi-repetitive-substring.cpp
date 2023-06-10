class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int l=0,r=1;
        int n = s.size();
        int cnt = 0;
        int ans = 1;
        while(r < n){
            if(r-1>=0 && s[r] == s[r-1]){
                cnt++;
                if(cnt > 1){
                    while(l <= r && s[l] != s[l+1]){
                        l++;
                    }
                    l++;
                    cnt--;
                }
            } 
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};