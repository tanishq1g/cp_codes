#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
#include <climits>
using namespace std;

int func(vector<vector<int> > &dp, int n, int k){
    // cout << n << ' ' << k << endl;
    if(n == 1){
        return k;
    }
    if(k == 1){
        return 1;
    }
    if(n == 0 || k == 0)
        return 0;
    if(dp[n][k] != -1)
        return dp[n][k];

    int mi = INT_MAX;
    for(int i = 1; i <= k; i++){
        mi = min(mi, max(func(dp, n - 1, i - 1), func(dp, n, k - i)) + 1);
    }
    dp[n][k] = mi;
    return mi;
}
// dynamic_programming
int main(){
    int t;
    cin >> t;
    vector<vector<int> > dp(11, vector<int> (51, -1));
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << func(dp, n, k)<<endl;;
    }
    return 0;
}