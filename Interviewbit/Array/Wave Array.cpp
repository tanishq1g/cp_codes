vector<int> Solution::wave(vector<int> &ve) {
    int n = ve.size();
    sort(ve.begin(), ve.end());
    for(int i = 0; i < n; i += 2){
        if(i + 1 < n){
            swap(ve[i], ve[i + 1]);
        }    
    }
    return ve;
}
