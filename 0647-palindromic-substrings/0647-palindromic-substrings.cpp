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
        cout<<temp<<"\n";
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
    bool checkPalindrome(int l,int r,string s,vector<int> &lps){
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
    int countSubstrings(string s) {
        Manacher obj1;
        vector<int> lps = obj1.generatelps(s);
        int cnt = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(obj1.checkPalindrome(i,j,s,lps)){
                    cnt++;
                }
            }
        } 
        return cnt;
    }
};