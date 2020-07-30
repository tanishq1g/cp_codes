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

int main(){
    unsigned int t;
    cin >> t;
    while(t--){
        unsigned int n;
        cin >> n;
        vector<unsigned int> ve(n);
        for(unsigned int i = 0; i < n; i++){
            cin >> ve[i];
        }
        vector<unsigned int> dp(n, UINT_MAX);
        dp[0] = 0;
        for(unsigned int i = 1; i < n; i++){
            for(unsigned int j = 0; j < i; j++){
                // cout << i << ' ' << j <<' '<<ve[j]<<' '<< dp[i] << endl;
                if(i - j <= ve[j]){
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] == UINT_MAX){
                cout << -1 << endl;
                continue;
            }
        }
        cout << dp[n - 1] << endl;
    }
    return 0;
}