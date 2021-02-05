int a, b;
void dfs(int x, int y, vector<string> &c, vector<vector<bool> > &vis, int dist){
    if(x < 0 || y < 0 || x >= a || y >= b)
        return;
    if(vis[x][y] < dist){
        return;
    }
    vis[x][y] = dist;
    int u = 0, r = 0, d = 0, l = 0;

    if(c[x][y] == 'U')
        u = 1;
    else if(c[x][y] == 'R')
        r = 1;
    else if(c[x][y] == 'D')
        d = 1;
    else if(c[x][y] == 'L')
        l = 1;
    dfs(x, y - 1, c, vis, dist + u);
    dfs(x + 1, y, c, vis, dist + r);
    dfs(x, y + 1, c, vis, dist + d);
    dfs(x - 1, y, c, vis, dist + l);
}
int Solution::solve(int aa, int bb, vector<string> &c) {
    a = aa;
    b = bb;
    vector<vector<int> > vis(a, vector<int> (b, INT_MAX));
    
    dfs(0, 0, c, vis, 0)
    return vis[a - 1][b - 1];
}
