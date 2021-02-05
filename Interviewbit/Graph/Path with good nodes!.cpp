int ct;
void dfs(vector<vector<int> > &gr, vector<bool> &vis, vector<int> &a, int cur, int c){
    vis[cur] = true;
    int sa = gr[cur].size();
    if(a[cur] == 1){
        c--;
    }
    bool flag = true;
    for(int i = 0; i < sa; i++){
        if(vis[gr[cur][i]] == false){
            dfs(gr, vis, a, gr[cur][i], c);
            flag = false;
        }
    }
    if(flag){
        if(c >= 0){
            ct++:
            return;
        }
    }
}
int Solution::solve(vector<int> &a, vector<vector<int> > &b, int c) {
    int n = a.size();
    vector<bool> vis(n, false);
    vector<vector<int> > gr(n, vector<int> ());
    int nb = b.size();
    ct = 0;
    for(int i = 0; i < nb; i++){
        gr[b[i][0] - 1].push_back(b[i][1] - 1);
        gr[b[i][1] - 1].push_back(b[i][0] - 1);
    }  
    dfs(gr, vis, a, 0, c);
    return ct;
}
