int n;
int func(string &str, vector<vector<int> > &dp, int x, int y){
    if(x < 0 || y >= n)
        return;
    if(x == n)
        return 0;
    if(dp[x][y] != -1)
        return dp[x][y];
    if(x == y){
        dp[x][y] = 1;
        return 1;
    }
    if(str[x] == str[y]){
        if(x == y - 1){
            dp[x][y] = 2;
        }
        else
            dp[x][y] = func(str, dp, x + 1, y - 1) + 2;
    }
    else{
        dp[x][y] = max(func(str, dp, x, y - 1), func(str, dp, x + 1, y));
    }
    return dp[x][y];
}

int Solution::solve(string str) {
    n = str.size();
    vector<vector<int> > dp(n + 1, vector<int> (n, -1)); 
    return func(str, dp, 0, n - 1);
}
