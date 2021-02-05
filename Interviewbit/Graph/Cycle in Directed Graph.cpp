bool dfs(vector<vector<int> > &gr, vector<bool> &vis, vector<bool> &recvis, int cur){
    vis[cur] = true;
    recvis[cur] = true;
    int ss = gr[cur].size();
    for(int i = 0; i < ss; i++){
        if(vis[gr[cur][i]] == false){
            if(dfs(gr, vis, recvis, gr[cur][i])){
                return true;
            }
        }
        else if(recvis[gr[cur][i]]){
            return true;
        }
    }
    recvis[cur] = false;
    return false;
}

int Solution::solve(int a, vector<vector<int> > &b) {
    vector<bool> vis(a, false);
    vector<bool> recvis(a, false);
    vector<vector<int> > gr(a, vector<int> ());
    int n = b.size(); 
    for(int i = 0; i < n; i++){
        gr[b[i][0] - 1].push_back(b[i][1] - 1);
    }
    for(int i = 0; i < a; i++){
        if(vis[i] == false){
            if(dfs(gr, vis, recvis, i)){
                return true;
            }
        }
    }
    return false;
}
