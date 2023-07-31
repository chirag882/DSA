class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        set<string> st;
        for(auto it : forbidden){
            st.insert(it);
        }
        int n = word.size();
        int i=0,j=0;
        int ans = 0;
        while(j < n){
            int idx = -1;
            for(int k=j;k>j-10 && k>=i;k--){
                string temp = word.substr(k,j-k+1);
                if(st.find(temp) != st.end()){
                    i = k+1;
                    break;
                }
            }
            ans = max(ans,j-i+1);            
            j++;
        }
        return ans;
    }
};