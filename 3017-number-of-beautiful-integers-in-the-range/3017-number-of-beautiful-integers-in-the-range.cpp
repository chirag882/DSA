class Solution {
public:
    int k;
    int dp[12][2][20][12][12][2];
    int  rec(int idx,int tight,int sum,int even,int odd,string &s,int iszero){
        // base
        if(idx == s.size()){
            if(iszero == 0 && sum == 0 && even == odd){
                return 1;
            }
            return 0;
        }
        // cache
        if(dp[idx][tight][sum][even][odd][iszero] != -1){
            return dp[idx][tight][sum][even][odd][iszero];
        }
        // compute
        int ans = 0;
        int ub = (tight == 1) ? s[idx] - '0' : 9;
        for(int i=0;i<=ub;i++){
            int newtight = (i == ub) ? tight : 0;
            if(iszero && i == 0){
                ans += rec(idx+1,newtight,sum,even,odd,s,iszero);
            }else{
                int newmod = (sum*10+i) % k;
                int newodd = odd;
                int neweven = even;
                if(i % 2){
                    newodd++;
                }else{
                    neweven++;
                }
                ans += rec(idx+1,newtight,newmod,neweven,newodd,s,0);
            }
        } 
        return dp[idx][tight][sum][even][odd][iszero] = ans;
    }

    int numberOfBeautifulIntegers(int low, int high, int kk) {
        k = kk;
        string l = to_string(low-1);
        string r = to_string(high);
        memset(dp,-1,sizeof(dp));
        int right = rec(0,1,0,0,0,r,1);
        memset(dp,-1,sizeof(dp));
        int left = rec(0,1,0,0,0,l,1);
        return right - left;
    }
};