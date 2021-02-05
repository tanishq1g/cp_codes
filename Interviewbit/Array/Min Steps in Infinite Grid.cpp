int Solution::coverPoints(vector<int> &a, vector<int> &b) {
    int n_moves = 0;
    for(int i = 0; i < a.size() - 1; i++){
        int hor = abs(a[i] - a[i + 1]);
        int ver = abs(b[i] - b[i + 1]);

        int min_diag_moves = min(hor, ver);
        int min_hor_moves = max(hor, ver) - min_diag_moves;

        n_moves += min_diag_moves + min_hor_moves;

        // cout<<n_moves<<' '<<min_diag_moves<<' '<<min_hor_moves<<'\n';
    }
    return n_moves;
    
}
