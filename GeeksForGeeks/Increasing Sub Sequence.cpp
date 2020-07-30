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
    string s;
    while(t--){
        cin >> s;
        int slen = s.size(), ml = 0;
        vector<int> dp(slen, 1);
        for(int i = 0; i < slen; i++){
            for(int j = 0; j < i; j++){
                if(s[j] < s[i]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ml = max(ml, dp[i]);
        }
        cout << ml << endl;
    }
    return 0;
}