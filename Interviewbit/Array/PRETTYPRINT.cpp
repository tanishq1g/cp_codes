vector<vector<int> > Solution::prettyPrint(int x) {
    int n = 2 * x - 1;
    vector<vector<int> > pr(n, vector<int> (n, 1));
    for(int i = 0; i < n; i++){
        for(int j = i; j < n - i; j++){
            pr[i][j] = x;
            pr[j][i] = x;
            pr[n - i - 1][j] = x;
            pr[j][n - i - 1] = x;
        }    
        x--;
    } 
    return pr;
}
