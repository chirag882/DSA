class Solution {
public:
    string countAndSay(int n) {
        vector<string> v(n+1);
        v[1] = "1";
        for(int i=2;i<=n;i++){
            string temp = v[i-1];
            string curr = "";
            int m = temp.size();
            for(int j=0;j<m;j++){
                int k = j;
                char uu = temp[j];
                while(k+1 < m && temp[k+1] == temp[k]){
                    k++;
                }
                curr += to_string(k-j+1);
                curr += uu;
                v[i] = curr;
                j = k;
            }
        }
        return v[n];
    }
};