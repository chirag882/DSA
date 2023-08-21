class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = s.length()/2; i >= 1; i--) {
            if(s.length() % i == 0) {
                string sub = s.substr(0, i);
                string temp = "";
                
                while(temp.size() < s.size()) 
                    temp += sub;
                
                if(temp == s) return true;
            }
        }
        return false;
    }
};