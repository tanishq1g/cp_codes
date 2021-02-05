int Solution::uniquePaths(int a, int b) {
    a--;b--;
    vector<vector<int> > dp(a + 1, vector<int> (b + 1, 1));
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    } 
    return dp[a][b];
}
