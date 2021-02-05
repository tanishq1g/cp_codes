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
// bits

int main(){
    int t, n, n2 = 2, count;
    cin >> t;
    vector<int> dp(10001); //minimum operations required to reach i is dp[i]
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    while(t--){
        cin >> n;
        if(n2 >= n){
            cout << dp[n];
        }
        else{
            for(int i = n2 + 1; i <= n; i++){
                dp[i] = min(dp[i - 1] + 1, dp[i/2] + 1 + (i - (i / 2) * 2) );
            }
            cout << dp[n] << endl;
        }
    }
    return 0;
}