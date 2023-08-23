class Solution {
public:
    vector<string> ans;
    int target;
    int n;
    void rec(int idx,string &num,string temp,long prev,long sum){
        if(idx == n){
            if(sum == target){
                ans.push_back(temp);
            }
            return;
        }
        for(int i=idx;i<n;i++){
            if(i > idx && num[idx] == '0'){
                break;
            }
            long tempval = stol(num.substr(idx,i-idx+1));
            string tempstr = num.substr(idx,i-idx+1);
            if(idx == 0){
                rec(i+1,num,tempstr,tempval,tempval);
            }else{
                rec(i+1,num,temp + '+' + tempstr,+tempval,sum+tempval);
                rec(i+1,num,temp + '-' + tempstr,-tempval,sum-tempval);
                rec(i+1,num,temp + '*' + tempstr,prev*tempval,sum-prev+(prev*tempval));
            }
        }
        return;
    }

    vector<string> addOperators(string num, int t) {
        target = t;
        n = num.size();
        string temp = "";
        rec(0,num,temp,0,0);
        return ans;
    }
};