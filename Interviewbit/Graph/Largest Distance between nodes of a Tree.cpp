int ma;
int dfs(int cur, vector<bool> &vis, vector<vector<int> > &gr){
    vis[cur] = true;
    int n = gr[cur].size();
    int m2 = 0, m1 = 0, m;
    for(int i = 0; i < n; i++){
        if(vis[gr[cur][i]] == false){
            m = dfs(gr[cur][i], vis, gr);
            if(m >= m2){
                m1 = m2;
                m2 = m;
            }
            else if(m >= m1){
                m1 = m;
            }
        }    
    }
    ma = max(m1 + m2, ma);
    return m2 + 1;
}
int Solution::solve(vector<int> &ve) {
    int n = ve.size();
    if(n <= 1)
        return 0;
    ma = 0;
    vector<vector<int> > gr(n, vector<int> ());
    vector<bool> vis(n, false);
    int ro; 
    for(int i = 0; i < n; i++){
        if(ve[i] == -1)
            ro = i;
        else{
            gr[ve[i]].push_back(i);
            gr[i].push_back(ve[i]);
        }
    } 
    return max(ma, dfs(ro, vis, gr) - 1);
}
