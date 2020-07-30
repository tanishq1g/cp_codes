#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;
// dynamic programming


int main(){
    int t, n, count;
    cin >> t;

    while(t--){
        cin >> n;
        vector<int> dp(n+1, 0);
        dp[0] = 1;  
        for(int i = 3; i <= n; i++){
            dp[i] += dp[i - 3];
        }
        for(int i = 5; i <= n; i++){
            dp[i] += dp[i - 5];
        }
        for(int i = 10; i <= n; i++){
            dp[i] += dp[i - 10];
        }
        cout << dp[n] << endl;
    }
    return 0;
}