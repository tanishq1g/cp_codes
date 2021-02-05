void dfs(vector<vector<int> > &gr, vector<bool> &vis, int cur){
    vis[cur] = true;
    int ss = gr[cur].size();
    for(int i = 0; i < ss; i++){
        if(vis[gr[cur][i]] == false){
            dfs(gr, vis, gr[cur][i]);
        }
    }
}

int Solution::solve(int a, vector<vector<int> > &b) {
    vector<bool> vis(a, false);
    vector<vector<int> > gr(a, vector<int> ());
    int n = b.size(); 
    for(int i = 0; i < n; i++){
        gr[b[i][0] - 1].push_back(b[i][1] - 1);
    }
    dfs(gr, vis, 0);    
    return vis[a - 1];
}
