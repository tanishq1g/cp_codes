#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;

// int main(){
//     int n, a, b, c, x, y, z, ma = INT_MIN;
//     cin >> n >> a >> b >> c;
//     for(int i = 0; i <= n; i++){
//         x = i * a;
//         if(x > n)
//             continue;
//         for(int j = 0; j <= n; j++){
//             y = j * b;
//             if(y > n || x + y > n)
//                 continue;
//             z = n - x - y;
//             if(z % c == 0){
//                 ma = max(i + j + z/c, ma);
//                 // cout << i<<' '<< j<<' '<< x<<' '<< y<<' '<< z<<"      "<<ma<<'\n';
//             } 
//         }
//     }
//     cout << ma;
//     return 0;
// }
// dynamic programming
int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(4001, 0);
    vector<int> ve{a, b, c};
    sort(ve.begin(), ve.end());
    dp[ve[0]] = 1;
    dp[ve[1]] = 1;
    dp[ve[2]] = 1;
    int x, y, z;
    for(int i = 0; i <= n; i++){
        x = y = z = 0;
        if(i >= ve[0] && dp[i - ve[0]] > 0){
            x = dp[i - ve[0]] + 1;
        }
        if(i >= ve[1] && dp[i - ve[1]] > 0){
            y = dp[i - ve[1]] + 1;
        }
        if(i >= ve[2] && dp[i - ve[2]] > 0){
            z = dp[i - ve[2]] + 1;
        }
        // cout << i << ' ' << x << ' ' << y << ' ' << z << '\n';
        dp[i] = max(x, max(y, max(z, dp[i])));
    }
    cout << dp[n];
    return 0;
}