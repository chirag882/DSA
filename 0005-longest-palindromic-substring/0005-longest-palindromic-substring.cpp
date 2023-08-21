class Solution {
public:
    string longestPalindrome(string s) {
        string temp = "";
        for(auto it : s){
            temp += '#';
            temp += it;
        }
        temp += '#';
        temp = '$' + temp;
        temp = temp + '*';
        int n = temp.size();
        vector<int> lps(n,0);
        for(int i=1;i<n-1;i++){
            while(temp[i+1+lps[i]] == temp[i-1-lps[i]]){
                lps[i]++;
            }
        }
        int maxi = INT_MIN;
        int idx;
        for(int i=0;i<n;i++){
            if(maxi < lps[i]){
                maxi = lps[i];
                idx = i;
            }
        }
        cout<<temp<<"\n";
        cout<<maxi<<" "<<idx<<"\n";
        string ans = "";
        if(maxi % 2){
            int sz = 0;
            while(sz < maxi){
                ans = ans + temp[idx+sz];
                sz+=2;
            }
            string temp = ans.substr(1);
            reverse(temp.begin(),temp.end());
            ans = temp + ans;
        }else{
            int sz = 1;
            while(sz < maxi){
                ans = ans + temp[idx+sz];
                sz+=2;
            }
            string temp = ans;
            reverse(temp.begin(),temp.end());
            ans = temp + ans;
        }
        
        return ans;
    }
};