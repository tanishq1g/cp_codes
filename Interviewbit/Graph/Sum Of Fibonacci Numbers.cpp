int Solution::fibsum(int a) {
    vector<int> dp(2);
    dp[0] = 1;
    dp[1] = 1;
    if(a <= 1){
        return a;
    }
    while(dp.back() < a){
        dp.push_back(dp.back() + dp[dp.size() - 2]);
    }
    int count = 0;
    while(a != 0){
        auto itr = upper_bound(dp.begin(), dp.end(), a);
        if(itr == dp.end()){
            a -= dp.back();
            count++;
        }
        else{
            itr--;
            a -= *itr;
            count++;
        }
    }
    return count;
}
