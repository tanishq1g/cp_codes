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

int main(){
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        int n, m, ma = 0;
        cin >> n >> m;
        cin >> s1 >> s2;
        vector<vector<int> > dp(n+1, vector<int> (m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ma = max(ma, dp[i][j]);
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                // cout << i << ' ' << j << ' ' << dp[i][j] << endl;;
            }
        }
        cout << ma << endl;
    }
    return 0;
}