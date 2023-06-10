class Solution {
public:
    bool isFascinating(int n) {
        int n2 = n*2;
        int n3 = n*3;
        string first = to_string(n);
        string second = to_string(n2);
        string third = to_string(n3);
        string f = first + second + third;
        map<char,int> mp;
        bool fl = true;
        for(auto it : f){
            if(it == '0'){
                fl = false;
                break;
            }
            mp[it]++;            
        }
        if(fl == false){
            return fl;
        }
        for(auto it : mp){
            if(it.second > 1){
                fl = false;
                break;
            }
        }
        return fl;
    }
};