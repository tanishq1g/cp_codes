int Solution::longestSubsequenceLength(const vector<int> &ve) {
    int n = ve.size();
    vector<int> vi(n), vd(n);
    // for(int i = 0; i < n; i++){
    //     cin >> ve[i];   
    // }
    if(n == 1)
        return 1;
    if(n == 0)
        return 0;
    vi[0] = 1;
    vd[n - 1] = 1;
    for(int i = 1; i < n; i++){
        vi[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(ve[i] > ve[j] && vi[i] < vi[j] + 1){
                vi[i] = vi[j] + 1;
            }
        }
        // cout << i << ' ' << vi[i]<<'\n';
    }
    for(int i = n - 2; i >= 0; i--){
        vd[i] = 1;
        for(int j = i + 1; j < n; j++){
            if(ve[i] > ve[j] && vd[i] < vd[j] + 1){
                vd[i] = vd[j] + 1;
            }
        }
        // cout << i << ' ' << vd[i]<<'\n';
    }
    int out = INT_MIN;
    for(int i = 0; i < n; i++){
        out = max(out, vi[i] + vd[i] - 1);
    }
    return out;
}
