class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        map<int,vector<int>> mp;
        for(int i=0;i<g.size();i++){
            mp[g[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto it : mp){
            vector<int> v = it.second;
            int i = 0;
            while(i != v.size()){
                vector<int> temp;
                int u = it.first;
                while(u--){
                    temp.push_back(v[i++]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};