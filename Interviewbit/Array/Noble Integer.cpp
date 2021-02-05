int Solution::solve(vector<int> &ve) {
    int n = ve.size();
    sort(ve.begin(), ve.end());
    for(int i = 0; i < n; i++){
        if(i + 1 < n && ve[i] == ve[i + 1])
            continue;
        if(ve[i] == n - i - 1){
            return 1;
        }    
    }
    return -1;
}
