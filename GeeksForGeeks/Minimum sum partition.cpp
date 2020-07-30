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

int func(vector<vector<int> > &dp, vector<int> &ve, int n, int di){
    // cout << n << ' ' << di << '\n';
    if(n < 0){
        return di;
    }
    if(dp[n][di] != -1)
        return dp[n][di];
    dp[n][di] = min(func(dp, ve, n - 1, di + ve[n]), func(dp, ve, n - 1, abs(di - ve[n])));
    return dp[n][di];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, su = 0;
        cin >> n;
        vector<int> ve(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
            su += ve[i];
        }       
        vector<vector<int> > dp(n, vector<int> (su, -1));
        cout << func(dp, ve, n - 2, ve[n - 1]) << endl;
    }
    return 0;
}


// greedy
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         vector<int> ve(n);
//         for(int i = 0; i < n; i++){
//             cin >> ve[i];   
//         }       
//         sort(ve.begin(), ve.end());
//         int s1 = 0, s2 = 0;
//         for(int i = n - 1; i >= 0; i--){
//             if(s1 >= s2){
//                 s2 += ve[i];
//             }
//             else{
//                 s1 += ve[i];
//             }
//             // cout << s1 << ' ' << s2 << '\n';
//         }
//         cout << abs(s2 - s1) << endl;
//     }
//     return 0;
// }