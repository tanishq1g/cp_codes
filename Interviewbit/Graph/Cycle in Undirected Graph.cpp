bool dfs(vector<vector<int> > &gr, vector<bool> &vis, int cur, int par){
    vis[cur] = true;
    int ss = gr[cur].size();
    for(int i = 0; i < ss; i++){
        if(vis[gr[cur][i]] == false){
            if(dfs(gr, vis, gr[cur][i], cur)){
                return true;
            }
        }
        else if(gr[cur][i] != par){
            return true;
        }
    }
    return false;
}

int Solution::solve(int a, vector<vector<int> > &b) {
    vector<bool> vis(a, false);
    vector<vector<int> > gr(a, vector<int> ());
    int n = b.size(); 
    for(int i = 0; i < n; i++){
        gr[b[i][0] - 1].push_back(b[i][1] - 1);
        gr[b[i][1] - 1].push_back(b[i][0] - 1);
    }
    for(int i = 0; i < a; i++){
        if(vis[i] == false){
            if(dfs(gr, vis, i, -1)){
                return true;
            }
        }
    }
    return false;
}
