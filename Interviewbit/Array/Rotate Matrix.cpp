void Solution::rotate(vector<vector<int> > &ve) {
    int n = ve.size(), temp;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n - i - 1; j++){
            temp = ve[n - j - 1][i];
            ve[n - j - 1][i] = ve[n - i - 1][n - j - 1];
            ve[n - i - 1][n - j - 1] = ve[j][n - i - 1];
            ve[j][n - i - 1] = ve[i][j];
            ve[i][j] = temp;
        }
    }
}
