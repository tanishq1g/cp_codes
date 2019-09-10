#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;
// DYNAMIC PROGRAMMING
class Solution {
public:
    int minDistance(string word1, string word2) {
        int sw1 = word1.size(), sw2 = word2.size();
        if(sw1 == 0)
            return sw2;
        if(sw2 == 0)
            return sw1;
        vector<vector<int>> dp(sw1 + 1, vector<int> (sw2 + 1, 0));
        
        for(int i = 0; i <= sw1; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j <= sw2; j++){
            dp[0][j] = j;
        }

        for(int i = 1; i <= sw1; i++){
            for(int j = 1; j <= sw2; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }    
        }

        // for(int i = 0; i <= sw1; i++){
        //     for(int j = 0; j <= sw2; j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        return dp[sw1][sw2];
    }
};