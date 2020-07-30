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
        int n, m;
        cin >> n;
        vector<int> ve(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }
        cin >> m;

        vector<int> dp(m + 1, 0);
        sort(ve.begin(), ve.end());
        for(int i = 0; i < n; i++){
            dp[ve[i]] += 1;
            for(int j = ve[i] + 1; j <= m; j++){
                dp[j] += dp[j - ve[i]];
            }    
        }    
        cout << dp[m] << endl;
    }
    return 0;
}