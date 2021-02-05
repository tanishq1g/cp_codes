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
            }
        }
        cout << ma << endl;
    }
    return 0;
}


ABCDGH -s1 
ACDGHR -s2
   0  1  2  3  4  5  6   -- s1
0  0  ............   0
1  0  1  0  0  0  0  0
2  0  1  0  1  0  0  0 
3  0    2  2  2   
4  0
5  0
6  0

--s2