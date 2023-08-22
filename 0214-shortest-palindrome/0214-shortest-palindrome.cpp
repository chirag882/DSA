class Solution {
public:
    int lps(string temp){
        int n = temp.size();
        vector<int> lps(n,0);
        for(int i=1;i<n;i++){
            int j = lps[i-1];
            while(j > 0 && temp[i] != temp[j]){
                j = lps[j-1];
            }
            if(temp[i] == temp[j]){
                j++;
                lps[i] = j;
            }
        }
        return lps[temp.size()-1];
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string temp = s + '#' + rev; 
        int j = lps(temp);
        string u = s.substr(j);
        // cout<<u<<"\n";
        reverse(u.begin(),u.end());
        s = u + s;
        return s;
    }
};