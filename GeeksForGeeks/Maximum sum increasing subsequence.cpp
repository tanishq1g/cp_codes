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
        int n, ma = INT_MIN;
        cin >> n;
        vector<int> ve(n), dp(n, 0);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }       
        dp[0] = ve[0];
        ma = max(ma, dp[0]);

        for(int i = 1; i < n; i++){
            dp[i] = ve[i];
            for(int j = 0; j < i; j++){
                if(ve[j] < ve[i]){
                    dp[i] = max(dp[i], dp[j] + ve[i]);
                }
            }   
            ma = max(ma, dp[i]);
        }
        cout << ma << endl;
    }
    return 0;
}