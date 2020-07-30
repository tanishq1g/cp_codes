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
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        vector<vector<int> > dp(n + 1, vector<int> (m + 1));
        for(int i = 0; i <= n; i++){
            dp[i][0] = i;    
            
        }
        for(int i = 0; i <= m; i++){
            dp[0][i] = i;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }        
                else{
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            // cout << s1[i - 1] <<' ' << s2[j - 1] << ' ' << i<< ' ' << j << ' ' << dp[i][j] << endl;
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}