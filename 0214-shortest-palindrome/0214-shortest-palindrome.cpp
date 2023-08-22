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
    vector<int> generatelps(string s){
        vector<int> lps = LPS(s);
        return lps;
    }
    void longestPalindromeSubstring(string s,vector<int> &lps){
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
        cout<<ans<<"\n";
    }
    bool checkPalindrome(int l,int r,vector<int> &lps){
        int len = r-l+1;
        int mid;
        int lpsindex;
        if(len % 2){
            mid = (l+r)/2;
            lpsindex = 2*mid+2;
        }else{
            mid = (l+r)/2;
            lpsindex = 2*mid+3;
        }
        if(len <= lps[lpsindex]){
            return true;
        }else{
            return false;
        }
    }
};
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty()){
            return s;
        }
        Manacher obj1;
        vector<int> lps = obj1.generatelps(s);   
        int idx;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(obj1.checkPalindrome(0,i,lps)){
                idx = i;
            }
        }
        string u = s.substr(idx+1);
        reverse(u.begin(),u.end());
        s = u+s;
        return s;
    }
};