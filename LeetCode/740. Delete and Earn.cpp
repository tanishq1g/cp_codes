class Solution {
public:
    int deleteAndEarn(vector<int>& ve) {
        int n = ve.size();
        vector<int> dp(100001, 0);
        int ma = 0;
        for(int i = 0; i < n; i++){
            dp[ve[i]]++;    
            ma = max(ma, ve[i]);
        }
        dp[0] = dp[0] * 0;
        dp[1] = dp[1] * 1;
        for(int i = 2; i <= ma; i++){
            dp[i] = max(dp[i] * i + dp[i - 2], dp[i - 1]);
        }
        return dp[ma];
    }
};