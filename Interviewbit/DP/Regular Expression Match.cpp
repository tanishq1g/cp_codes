int na, nb;
int Solution::isMatch(const string a, const string b) {
    na = a.size();
    nb = b.size();
    vector<vector<bool> > dp(na + 1, vector<bool> (nb + 1, false));
    dp[0][0] = true;
    for(int i = 1; i <= nb; i++){
        if(b[i - 1] == '*')
            dp[0][i] = dp[0][i - 1];
    }
    for(int i = 1; i <= na; i++){
        for(int j = 1; j <= nb; j++){
            if(a[i - 1] == b[j - 1] ){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(b[j - 1] == '*'){
                dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
            }
            else if(b[j - 1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = false;
            }
        }
    } 
    return dp[na][nb];
}
