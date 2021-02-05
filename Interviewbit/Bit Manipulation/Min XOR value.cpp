int Solution::findMinXor(vector<int> &ve) {
    int n = ve.size();
    sort(ve.begin(), ve.end());
    int mi = 0;
    for(int i = 1; i < n; i++){
        mi = min(mi, ve[i] ^ ve[i - 1]);
    }
    return mi;
}
