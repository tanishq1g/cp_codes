class Solution {
public:
    int numDecodings(string s) {
        int ss = s.size();
        vector<unsigned long long int> dp(ss, 0);
        if(ss == 0)
            return 0;
        if(s[0] == '0')
            return 0;
        dp[0] = 1;
        for (int i = 1; i < ss; i++){
            if(s[i] == '0'){
                if(s[i - 1] == '1' || s[i - 1] == '2'){
                    if(i-2>=0)
                        dp[i] = dp[i - 2];
                    else
                        dp[i] = dp[i-1];
                    continue;
                }
                else
                    return 0;
            }
            if(s[i - 1] == '1' || (s[i - 1] == '2' && (s[i] >= '0' && s[i] <= '6'))){
                if(i-2 >= 0)
                    dp[i] = dp[i - 1] + dp[i - 2];
                else
                    dp[i] = dp[i - 1] + 1;
            }
            else{
                dp[i] = dp[i-1];
            } 
            // cout<<i<<' '<<s[i]<<' '<<dp[i]<<'\n';
        }
        return dp[ss - 1];
    }
};