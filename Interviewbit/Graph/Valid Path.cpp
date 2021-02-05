bool dfs(int x, int y, int &a, int &b, vector<vector<bool> > &ve){
    // cout << x << ' ' << y << '\n';
    if(x < 0 || x > a || y < 0 || y > b){
        return false;
    }
    if(ve[x][y] == false)
        return false;
    if(x == a && y == b)
        return true;
    ve[x][y] = false;
    bool ret = false;
    ret |= dfs(x - 1, y, a, b, ve);
    ret |= dfs(x - 1, y + 1, a, b, ve);
    ret |= dfs(x - 1, y - 1, a, b, ve);
    ret |= dfs(x + 1, y, a, b, ve);
    ret |= dfs(x + 1, y - 1, a, b, ve);
    ret |= dfs(x + 1, y + 1, a, b, ve);
    ret |= dfs(x, y - 1, a, b, ve);
    ret |= dfs(x, y + 1, a, b, ve);
    return ret;
}

string Solution::solve(int a, int b, int n, int r, vector<int> &x, vector<int> &y) {
    vector<vector<bool> > ve(a + 1, vector<bool> (b + 1, true));
    int tx, ty;
    for(int k = 0; k < n; k++){
        ve[x[k]][y[k]] = false; 
        int xl = max(0, x[k] - r + 1), xr = min(a, x[k] + r - 1);
        for(int i = xl; i <= xr; i++){
            int yl = max(0, y[k] - r + 1), yr = min(b, y[k] + r - 1);
            for(int j = yl; j <= yr; j++){
                // cout << i << ' ' << j << '\n';
                ve[i][j] = false;
            }
            tx = x[k] - r;
            if(tx >= 0 && tx <= a){
                ve[tx][y[k]] = false;
            }
            tx = x[k] + r;
            if(tx >= 0 && tx <= a){
                ve[tx][y[k]] = false;
            }
            ty = y[k] - r;
            if(ty >= 0 && ty <= b){
                ve[x[k]][ty] = false;
            }
            ty = y[k] + r;
            if(ty >= 0 && ty <= b){
                ve[x[k]][ty] = false;
            }
        }
    }
    // for(int i = 0; i <= a; i++){
    //     for(int j = 0; j <= b; j++){
    //         cout << ve[i][j] << ' ';
    //     } cout << endl;
    // } cout << endl;

    if(dfs(0, 0, a, b, ve)){
        return "YES";
    }
    return "NO";
}
