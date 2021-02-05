vector<int> Solution::nextPermutation(vector<int> &ve) {
    int n = ve.size();
    int l = -1;
    for(int i = n - 1; i > 0; i--){
        if(ve[i] > ve[i - 1]){
            l = i - 1;
            break;
        }
    }
    if(l == -1){
        reverse(ve.begin(), ve.end());
        return ve;
    }
    bool flag = true;
    // cout << l << '\n';
    for(int i = l + 1; i < n; i++){
        if(ve[i] < ve[l]){
            swap(ve[i - 1], ve[l]);
            reverse(ve.begin() + l + 1, ve.end());
            flag = false;
            break;
        }
    }
    if(flag){
        swap(ve[l], ve[n - 1]);
        reverse(ve.begin() + l + 1, ve.end());
    }
    return ve;
}
