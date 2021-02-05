int Solution::maximumGap(const vector<int> &ve) {
    int n = ve.size();
    if(n <= 1)
        return 0;
    vector<pair<int, int>> dp(n);
    for(int i = 0; i < n; i++){
        dp[i] = make_pair(ve[i], i);
    } 
    sort(dp.begin(), dp.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        return a.first < b.first;
    });

    int ma = INT_MIN;
    int mi = dp[0].second;
    for(int i = 1; i < n; i++){
        ma = max(ma, dp[i].second - mi);
        mi = min(mi, dp[i].second);
    }
    return max(ma, 0);
}
