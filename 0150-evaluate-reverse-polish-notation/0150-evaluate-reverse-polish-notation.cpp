class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> st;
        int n = t.size();
        for(int i=0;i<n;i++){
            if((t[i] == "+" || t[i] == "-" || t[i] == "*" || t[i] == "/")){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop(); 
                int ans;
                if(t[i] == "+"){
                    ans = first + second;
                }else if(t[i] == "-"){
                    ans = first - second;
                }else if(t[i] == "*"){
                    ans = first * second;
                }else if(t[i] == "/"){
                    ans = first / second;
                }
                st.push(ans);
            }else{
                st.push(stoi(t[i]));
            }
        }
        return st.top();
    }
};