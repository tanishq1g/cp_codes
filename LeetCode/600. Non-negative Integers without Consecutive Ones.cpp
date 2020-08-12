class Solution {
public:
    int findIntegers(int num) {
        vector<int> dp(32, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < 32; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }     
        int count = 0;
        int l = -1;
        for(int i = 31; i >= 0; i--){
            if((1 << i & num) > 0){
                count += dp[i];
                if(l - i == 1)
                    break;
                l = i;
            }
        }
        return count;
    }
};