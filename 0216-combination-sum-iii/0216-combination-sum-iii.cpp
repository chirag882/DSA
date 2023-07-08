class Solution {
public:

    void rec(int i,vector<int> &temp,int grp,int k,int n,vector<vector<int>> &ans){
        //base 
        if(grp == k){
            int sum = 0;
            for(auto it : temp){
                sum += it;
            }
            cout<<sum<<"\n";
            if(sum == n){
                ans.push_back(temp);
            }
        }
        if(grp > k){
            return;
        }
        if(i > 9){
            return;
        }
        
        // comupte
        // take
        temp.push_back(i);
        rec(i+1,temp,grp+1,k,n,ans);
        // not take
        temp.pop_back();
        rec(i+1,temp,grp,k,n,ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        set<vector<int>> st;
        rec(1,temp,0,k,n,ans);
        for(auto it : ans){
            st.insert(it);
        }
        vector<vector<int>> fans;
        for(auto it : st){
            fans.push_back(it);
        }
        
        return fans;
    }
};