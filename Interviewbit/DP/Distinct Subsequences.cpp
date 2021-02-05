int Solution::numDistinct(string a, string b) {
    int na = a.size();
    int nb = b.size();
    vector<vector<int> > dp(nb + 1, vector<int> (na + 1, 0));
    for(int i = 0; i <= na; i++){
        dp[0][i] = 1;
    }
    for(int i = 1; i <= nb; i++){
        for(int j = i; j <= na; j++){
            if(b[i - 1] == a[j - 1]){
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    // for(int i = 1; i <= nb; i++){
    //     for(int j = 1; j <=na; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return dp[nb][na];
}

// As a typical way to implement a dynamic programming algorithm, we construct a matrix dp, where each cell dp[i][j] represents the number of solutions of aligning substring T[0..i] with S[0..j];

// Rule 1). dp[0][j] = 1, since aligning T = “” with any substring of S would have only ONE solution which is to delete all characters in S.

// Rule 2). when i > 0, dp[i][j] can be derived by two cases:

// case 1). if T[i] != S[j], then the solution would be to ignore the character S[j] and align substring T[0..i] with S[0..(j-1)]. Therefore, dp[i][j] = dp[i][j-1].

// case 2). if T[i] == S[j], then first we could adopt the solution in case 1), but also we could match the characters T[i] and S[j] and align the rest of them (i.e. T[0..(i-1)] and S[0..(j-1)]. As a result, dp[i][j] = dp[i][j-1] + d[i-1][j-1]

// e.g. T = B, S = ABC

// dp[1][2]=1: Align T’=B and S’=AB, only one solution, which is to remove character A in S’.