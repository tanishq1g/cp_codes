#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
using namespace std;

// dynamic_programming

void findsum(vector<int> &dp, int n){
    if(dp[n] || n == 0){
        return;
    }
    if(!dp[n/2])
        findsum(dp, n / 2);
    if(!dp[n/3])
        findsum(dp, n / 3);
    if(!dp[n/4])
        findsum(dp, n / 4);

    dp[n] = max(dp[n / 2] + dp[n / 3] + dp[n / 4], n);
    // cout << n << ' ' << dp[n] << endl;
}
int main(){
    int t0, n, count, slen;
    cin >> t0;
    vector<int> dp(100001, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    while(t0--){
        cin >> n;
        findsum(dp, n);
        cout << dp[n] << endl;
    }
    return 0;
}