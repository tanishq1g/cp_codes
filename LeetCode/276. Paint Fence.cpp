// dynamic programming

class Solution {
public:
    int numWays(int n, int k) {
        if(n==0)return 0;
        if(k==0)return 0;
        vector<int> dp(n+1);
        dp[1]=k;
        if(n==1)return k;
        dp[2]=k*k;
        if(n==2)return k*k;
        for(int i=3;i<=n;i++)
            dp[i]=(k-1)*(dp[i-1]+dp[i-2]);
        return dp[n];
    }

};