bool dfs(int cur, vector<bool> &vis, vector<bool> &recvis, vector<vector<int> > &ve){
    vis[cur] = true;
    recvis[cur] = true;
    int n = ve[cur].size();

    for(int i = 0; i < n; i++){
        if(vis[ve[cur][i]] == false){
            if(dfs(ve[cur][i], vis, recvis, ve)){
                return true;
            }
        }
        else if(recvis[ve[cur][i]]){
            return true;
        }
    }
    recvis[cur] = false;

    return false;
}
int Solution::solve(int n, vector<int> &b, vector<int> &c) {
    vector<vector<int> > ve(n + 1, vector<int> ());
    vector<bool> vis(n + 1, false); 
    vector<bool> recvis(n + 1, false); 
    int s = b.size(); 
    for(int i = 0; i < s; i++){
        ve[b[i]].push_back(c[i]);
    }

    for(int i = 1; i < n; i++){
        if(vis[i] == false){
            if(dfs(i, vis, recvis, ve)){
                return 0;
            }
        }
    }
    return 1;
}
