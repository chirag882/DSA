class Solution {
public:

    bool helper(int n,multiset<int> st){
        multiset<int> temp = st;
        temp.erase(temp.find(n));
        if(temp.find(n) != temp.end()){
            return false;
        }
        return true;
    }

    int minDeletions(string s) {
        multiset<int> st;
        map<char,int> mp;
        for(auto it : s){
            mp[it]++;
        }
        for(auto it : mp){
            st.insert(it.second);
        }
        // for(auto it : st){
        //     cout<<it<<" ";
        // }cout<<'\n';
        int ans = 0;
        for(auto it : st){
            if(helper(it,st)){
                continue;
            }else{
                st.erase(st.find(it));
                int temp = it;
                while(temp > 0 && st.find(temp) != st.end()){
                    temp--;
                    ans++;
                }
                if(temp > 0){
                    st.insert(temp);
                }
            }
            
        }
        return ans;
    }
};