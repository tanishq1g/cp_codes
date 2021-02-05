void Solution::arrange(vector<int> &ve) {
    int n = ve.size();
    for(int i = 0; i < n; i++){
        ve[i] = ve[i] + (ve[ve[i]] % n) * n ;    
    }
    for(int i = 0; i < n; i++){
        ve[i] /= n;    
    }
}
