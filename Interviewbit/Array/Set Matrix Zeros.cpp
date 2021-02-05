void Solution::setZeroes(vector<vector<int> > &ve) {
    int m = ve.size();
    int n = ve[0].size();
    vector<bool> r(m, false);
    vector<bool> c(n, false);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(ve[i][j] == 0){
                r[i] = true;
                c[j] = true;
            }
        }
    } 
    for(int i = 0; i < m; i++){
        if(r[i]){
            for(int j = 0; j < n; j++){
                ve[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(c[i]){
            for(int j = 0; j < m; j++){
                ve[j][i] = 0;
            }
        }
    }
}
