bool dfs(vector<string> &ve, string &b, int x, int y, int cur, int &n, int &m){
    if(x < 0 || y < 0 || x >= n || y >= m){
        return false;
    }
    if(ve[x][y] != b[cur])
        return false;
    if(cur == b.size() - 1){
        return true;
    }
    return dfs(ve, b, x - 1, y, cur + 1, n, m) || dfs(ve, b, x + 1, y, cur + 1, n, m) || dfs(ve, b, x, y - 1, cur + 1, n, m) || dfs(ve, b, x, y + 1, cur + 1, n, m);
}
int Solution::exist(vector<string> &ve, string b) {
    int n = ve.size();
    if(n == 0)
        return 0;
    int m = ve[0].size();
    if(b.size() == 0)
        return 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ve[i][j] == b[0]){
                if(dfs(ve, b, i, j, 0, n, m)){
                    return 1;
                }
            }
        }
    }
    return 0;
}
