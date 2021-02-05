void dfs(int x, int y, vector<vector<bool> > &vis, vector<string> &ve, int &n, int &m){
    if(x < 0 || y < 0 || x >= n || y >= m){
        return;
    }
    if(vis[x][y] || ve[x][y] != 'X')
        return;
    vis[x][y] = true;
    dfs(x - 1, y, vis, ve, n, m);
    dfs(x + 1, y, vis, ve, n, m);
    dfs(x, y - 1, vis, ve, n, m);
    dfs(x, y + 1, vis, ve, n, m);
}
int Solution::black(vector<string> &ve) {
    int n = ve.size();
    if(n == 0)
        return 0;
    int m = ve[0].size();
    vector<vector<bool> > vis(n, vector<bool> (m, false));
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ve[i][j] == 'X' && vis[i][j] == false){
                cout << i << ' ' << j << '\n';
                dfs(i, j, vis, ve, n, m);
                count++;
            }
        }    
    }
    return count;
}
