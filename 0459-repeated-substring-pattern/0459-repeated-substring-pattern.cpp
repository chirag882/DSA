class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n == 1){
            return false;
        }
        int r = 0;
        string res = "";
        while(r < n/2){
            res += s[r];
            string temp = res;
            while(temp.size() < s.size()){
                temp += res;
            }
            if(temp == s)return true;
            r++;
        }
        return false;
    }
};