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

// dynamic_programming


int func(vector<vector<int> > &dp, vector<int> &ve, int l, int r){
        // cout << l << ' ' << r << ' ' << endl;
    if(l > r){
        return 0;
    } 
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    if(l == r){
        dp[l][r] = ve[l];
        // cout << l << ' ' << r << ' ' << dp[l][r] << ' ' <<endl;
        return dp[l][r];
    }
    func(dp, ve, l + 1, r); //left pick
    func(dp, ve, l, r - 1); //right pick

    dp[l][r] = max(
        min(func(dp, ve, l + 2, r), func(dp, ve, l + 1, r - 1)) + ve[l],
        min(func(dp, ve, l + 1, r - 1), func(dp, ve, l, r - 2)) + ve[r]
    );
    // cout << l << ' ' << r << ' ' << dp[l][r] <<endl;
    return dp[l][r];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ve(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];
        }       
        int ctr = 0;
        vector<vector<int> > dp(n, vector<int> (n,-1));

        cout << func(dp, ve, 0, n - 1) << endl;
    }
    return 0;
}