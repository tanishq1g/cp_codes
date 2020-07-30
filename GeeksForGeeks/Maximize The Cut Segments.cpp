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
    int t;
    cin >> t;
    while(t--){
        int n;
        vector<int> ve(3);
        cin >> n >> ve[0] >> ve[1] >> ve[2];

        sort(ve.begin(), ve.end());
        vector<int> dp(n + 1, 0);

        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 3; j++){
                if(i - ve[j] < 0){
                    dp[i] = max(dp[i], 0);
                }
                else if(i - ve[j] == 0){
                    dp[i] = max(dp[i], 1);
                }
                else{
                    if(dp[i - ve[j]] == 0)
                        dp[i] = max(dp[i], 0);
                    else
                        dp[i] = max(dp[i], dp[i - ve[j]] + 1);
                }
                // cout << i << ' ' << j << ' ' << dp[i] << endl; 
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}