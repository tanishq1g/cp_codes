class Solution {
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int nstrs = strs.size(), ss;        
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        vector<pair<int, int> > ve(nstrs, pair<int, int> {0, 0});

        for(int i = 0; i < nstrs; i++){
            ss = strs[i].size();
            for(int j = 0; j < ss; j++){
                if(strs[i][j] == '0')
                    ve[i].first++;
                else
                    ve[i].second++;
            }
        } 

        for(int s = 0; s < nstrs; s++){
            for(int i = m; i >= ve[s].first; i--){
                for(int j = n; j >= ve[s].second; j--){
                    dp[i][j] = max(dp[i - ve[s].first][j - ve[s].second] + 1, dp[i][j]);
                }
            }
        }
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        return dp[m ][n];
    }
};

// dp[i][j] denotes the maximum number of strings that can be included in the subset given only i 0's and j 1's are available.