class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        int ans = 0;
        int i;
        for(i=0;i<n;i++){
            if(st.empty() || h[i] >= h[st.top()]){
                st.push(i);
            }else{
                while(!st.empty() && h[i] < h[st.top()]){
                    int ht = h[st.top()];
                    st.pop();
                    ans = max(ans,ht*(st.empty() ? (i) : i-st.top()-1));
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            int ht = h[st.top()];
            st.pop();
            ans = max(ans,ht*(st.empty() ? (i) : i-st.top()-1));
            cout<<ans<<"\n";
        }
        return ans;
    }
};