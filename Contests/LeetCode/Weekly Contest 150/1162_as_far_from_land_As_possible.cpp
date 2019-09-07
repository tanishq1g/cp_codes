
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

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int sg = grid.size();
        vector<vector<int>> dp(sg, vector<int>(sg, -1));
        int r, c;
        int ch = 0;
        int fr = -1, fc = -1;
        int ma = 0;
        int up,dow,le,ri;
        for(int i = 0; i < sg; i++){
            fr = -1; fc = -1;
            for(int j = 0; j < sg; j++){
                if(grid[i][j] == 1){
                    if(fr == -1){
                        fr = i; fc = j;
                    }
                    dp[i][j] = 0;
                    ch++;
                    r = i - 1;
                    if(r >= 0)
                        if(dp[r][j] != 0) 
                            dp[r][j] = 1;
                    r = i + 1;
                    if(r < sg)
                        if(dp[r][j] != 0) 
                            dp[r][j] = 1;
                    c = j - 1;
                    if(c >= 0)
                        if(dp[i][c] != 0) 
                            dp[i][c] = 1;
                    c = j + 1;
                    if(c < sg)
                        if(dp[i][c] != 0) 
                            dp[i][c] = 1;
                }
            }
            if(fr != -1){
            for(int l = fr; l >= 0; l--){
                for(int m = fc; m >= fc; m--){
                    // cout<<l<<' '<<m<<'\n';
                    if(dp[l][m] == -1){
                        if(l == 0)
                            up = INT_MAX;
                        else
                            if(dp[l - 1][m] == -1)
                                up = INT_MAX;
                            else    
                                up = dp[l - 1][m];
                        if(m == 0)
                            le = INT_MAX;
                        else
                            if(dp[l][m - 1] == -1)
                                le = INT_MAX;
                            else    
                                le = dp[l][m - 1];
                        if(l == sg - 1)
                            ri = INT_MAX;
                        else
                            if(dp[l + 1][m] == -1)
                                ri = INT_MAX;
                            else    
                                ri = dp[l + 1][m];
                        if(m == sg - 1)
                            dow = INT_MAX;
                        else
                            if(dp[l][m + 1] == -1)
                                dow = INT_MAX;
                            else    
                                dow = dp[l][m + 1];
                        dp[l][m] = max(dp[l][m], min(up, min(min(dow, le), ri)) + 1);
                        ma = max(ma, dp[l][m]);
                    }
                    // for(lnt r = 0; r < sg; r++){
                    //     for(lnt c = 0; c < sg; c++){
                    //         cout<<dp[r][c]<<' ';
                    //     }
                    //     cout<<'\n';
                    // }
                    // cout<<'\n';
                }
            }}
        }
        if(ch == 0 || ch == sg*sg)
            return -1;
        

        // cout<<"ASdfasfasfasdf\n";
        for(int i = 0; i < sg; i++){
            for(int j = 0; j < sg; j++){
                // cout<<i<<' '<<j<<'\n';
                if(dp[i][j] == -1){
                    if(i == 0)
                        up = INT_MAX;
                    else
                        if(dp[i - 1][j] == -1)
                            up = INT_MAX;
                        else    
                            up = dp[i - 1][j];
                    if(j == 0)
                        le = INT_MAX;
                    else
                        if(dp[i][j - 1] == -1)
                            le = INT_MAX;
                        else    
                            le = dp[i][j - 1];
                    if(i == sg - 1)
                        ri = INT_MAX;
                    else
                        if(dp[i + 1][j] == -1)
                            ri = INT_MAX;
                        else    
                            ri = dp[i + 1][j];
                    if(j == sg - 1)
                        dow = INT_MAX;
                    else
                        if(dp[i][j + 1] == -1)
                            dow = INT_MAX;
                        else    
                            dow = dp[i][j + 1];
                    dp[i][j] = max(dp[i][j], min(up, min(min(dow, le), ri)) + 1);
                    ma = max(ma, dp[i][j]);
                }
            }
        }
                for(int r = 0; r < sg; r++){
                    for(int c = 0; c < sg; c++){
                        cout<<dp[r][c]<<' ';
                    }
                    cout<<'\n';
                }
                cout<<'\n';
        return ma;
    }
};

int main(){
    Solution sol;
    // vector<string> words {"catc","bt","hat","tree"};

    cout<<sol.maxDistance(grid);
}

