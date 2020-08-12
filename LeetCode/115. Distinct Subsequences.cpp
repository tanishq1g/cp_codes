// dynamic programming string

class Solution {
public:
    int numDistinct(string s, string t) {
        int ss = s.size(), st = t.size();
        vector<vector<long long int > > dp(ss + 1, vector<long long int > (st + 1, 0));
        for(int i = 1; i <= ss; i++){
            for(int j = 1; j <= st && j <= i; j++){
                if(s[i - 1] == t[j - 1]){
                    if(j == 1)
                        dp[i][j] = dp[i - 1][j] + 1;
                    else{
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    }
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }

            }
        } 
        for(int i = 0; i <= ss; i++){
            for(int j = 0; j <= st && j <= i; j++){
                cout << dp[i][j] << ' ';
            } cout << endl;
        } cout << endl;
        return dp[ss][st];
    }
};