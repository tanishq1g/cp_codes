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

int knapsack(vector<int> &v, vector<int> &w, vector<vector<int> > &dp , int wmax, int n){
    if(n == 0 || wmax == 0){
        return 0;
    }
    if(dp[n][wmax] >= 0){
        return dp[n][wmax];
    }

    // cout << wmax << ' ' << n << endl;
    if(w[n - 1] > wmax){
        dp[n][wmax] = knapsack(v, w, dp, wmax, n - 1);
        return dp[n][wmax];
    }

    dp[n][wmax] = max(
        v[n - 1] + knapsack(v, w, dp, wmax - w[n - 1], n - 1),
        knapsack(v, w, dp, wmax, n - 1));
    return dp[n][wmax];
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, wmax;
        cin >> n >> wmax;
        vector<int> w(n), v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];  
        }
        for(int i = 0; i < n; i++){
            cin >> w[i];  
        }
        vector<vector<int> > dp(n + 1, vector<int> (wmax + 1, -1));
        cout << knapsack(v, w, dp, wmax, n) << endl;
        // cout << dp[n][wmax] << endl;
    }
    return 0;
}