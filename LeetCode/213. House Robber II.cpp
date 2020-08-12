class Solution {
public:
    int rob(vector<int>& ve) {
        int n = ve.size();
        if(n == 1)
            return ve[0];
        if(n == 2)
            return max(ve[0], ve[1]);
        vector<int> dp(n, 0);
        dp[0] = ve[0];
        dp[1] = max(ve[0], ve[1]);
        n--;
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + ve[i]);
        }
        int ma = dp[n - 1];
        dp[1] = ve[1];
        dp[2] = max(ve[2], ve[1]);
        for(int i = 3; i <= n; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + ve[i]);
        }
        ma = max(ma, dp[n]);
        return ma;
    }
};