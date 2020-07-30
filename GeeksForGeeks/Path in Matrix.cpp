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
int func(vector<vector<int> > &ve, vector<vector<int> > &dp, int r, int c, int &n){
    // cout << r << ' ' << c << ' ' << n << '\n';
    if(r < 0 || r >= n || c < 0 || c >= n){
        cout << ' ' << 0 << endl;
        return 0;
    }
    if(dp[r][c] != -1){
        return dp[r][c];
    }
    if(r == n - 1){
        dp[r][c] = ve[r][c];
        cout << ' ' << ve[r][c] << endl;
        return dp[r][c];
    }
    dp[r][c] = max(func(ve, dp, r + 1, c - 1, n), max(func(ve, dp, r + 1, c, n), func(ve, dp, r + 1, c + 1, n))) + ve[r][c];
    return dp[r][c];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, ma = 0;
        cin >> n;
        vector<vector<int> > ve(n, vector<int> (n)), dp(n, vector<int> (n, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> ve[i][j];
            }
        }       
        for(int i = 0; i < n; i++){
            dp[0][i] =func(ve, dp, 0, i, n);
            ma = max(ma, dp[0][i]);
        }
        cout << ma << '\n';
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}