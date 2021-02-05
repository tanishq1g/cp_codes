bool f(const string &A,const string &B,int i,int j ,vector<vector<int>> & dp){
    if(j == B.size()){
        return (i == A.size());
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    bool ans = false;
    bool fm = (i<A.size() && (A[i] == B[j] || B[j] == '.'));
    if(j+1<B.size() && B[j+1] == '*'){
        ans = f(A,B,i,j+2,dp) || (fm && f(A,B,i+1,j,dp));
    }
    else{
        ans = fm && f(A,B,i+1,j+1,dp);
    }
    return dp[i][j] = ans;
}


int Solution::isMatch(const string A, const string B) {
    int n = A.size(),m = B.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return f(A,B,0,0,dp);
}
