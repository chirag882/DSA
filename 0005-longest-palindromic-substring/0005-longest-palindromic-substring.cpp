class Manacher{
private:
    string updatedString(string s){
        string temp = "@";
        for(int i=0;i<s.size();i++){
            temp += "#";
            temp += s[i];
        }
        temp += "#";
        temp += "*";
        return temp;
    }
    vector<int> LPS(string s){
        string temp = updatedString(s);
        int n = temp.size();
        vector<int> lps(n,0);
        int c=0,r=0;
        for(int i=1;i<n-1;i++){
            int mirror = c-(i-c);
            if(i<r){
                lps[i]=min(lps[mirror],r-i);
            }
            while(temp[i + 1 + lps[i]] == temp[i - 1 - lps[i]]){
                lps[i]++;
            }
            if(i+lps[i]>r){
                r = i+lps[i];
                c = i;
            }
        }
        return lps;
    }
public:
    string longestPalindromeSubstring(string s){
        vector<int> lps = LPS(s);
        int idx;
        int maxi = INT_MIN;
        for(int i=1;i<lps.size()-1;i++){
            if(maxi < lps[i]){
                maxi = lps[i];
                idx = i;
            }
        }
        int startpoint = idx - maxi + 1 ;
        int actualidx = (startpoint - 2)/2;
        string ans = s.substr(actualidx,maxi);
        return ans;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        Manacher obj1;
        return obj1.longestPalindromeSubstring(s);
    }
};