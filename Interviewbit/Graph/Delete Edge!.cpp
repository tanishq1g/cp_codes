long long pr;
long long mod;
long long ts;
long long dfs(vector<vector<int> > &gr, vector<int> &vis, vector<int> &a, int cur){
    vis[cur] = 0;
    long long su = a[cur];
    long long ss = gr[cur].size();
    for(int i = 0; i < ss; i++){
        if(vis[gr[cur][i]] == -1){
            su = (su + dfs(gr, vis, a, gr[cur][i])) % mod;
        }
    }
    vis[cur] = su;
    pr = max(pr, (((ts - su) % mod) * su) % mod);
    // cout << cur << ' ' << (((ts - vis[cur]) % mod) * vis[cur]) % mod << ' ' << vis[cur] << ' ' << ts << '\n';
    return su;
}

int Solution::deleteEdge(vector<int> &a, vector<vector<int> > &b) {
    int n = a.size();
    vector<int> vis(n, -1);
    vector<vector<int> > gr(n, vector<int> ());
    int nn = b.size(); 
    for(int i = 0; i < nn; i++){
        gr[b[i][0] - 1].push_back(b[i][1] - 1);
        gr[b[i][1] - 1].push_back(b[i][0] - 1);
    }
    // for(int i = 0; i < a; i++){
    //     if(vis[i] == false){
            
    //     }
    // }
    for(int i = 0; i < n; i++){
        ts += a[i];    
    }
    pr = INT_MIN;
    mod = 1e9 + 7;
    dfs(gr, vis, a, 0);
    // for(int i = 0; i < n; i++){
    //     cout << vis[i] << ' ';
    // } cout << endl;

    return pr;
}
