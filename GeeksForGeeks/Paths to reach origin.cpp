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
    int t0;
    cin >> t0;
    vector<vector<int> > dp(26, vector<int>(26));
    for(int i = 0; i < 26; i++){
        dp[i][0] = 1;   
        dp[0][i] = 1;
    }
    for(int i = 1; i < 26; i++){
        for(int j = 1; j < 26; j++){
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    while(t0--){
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << endl;
    }
    return 0;
}