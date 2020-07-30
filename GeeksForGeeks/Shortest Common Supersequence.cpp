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
        string str1, str2;
        cin >> str1 >> str2;
        int s1 = str1.size(), s2 = str2.size();
        vector<vector<int> > dp(s1 + 1, vector<int> (s2 + 1, 0));
        for(int i = 0; i <= s1; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i <= s2; i++){
            dp[0][i] = i;
        }

        for(int i = 1; i <= s1; i++){
            for(int j = 1; j <= s2; j++){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }        
        cout << dp[s1][s2] << endl;
    }
    return 0;
}