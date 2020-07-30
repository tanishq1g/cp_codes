#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <queue>
#include <stack>
using namespace std;

// GRAPH
int n;

bool dfs(vector<vector<int> > &ve, vector<vector<bool> > &vis, int r, int c){
    if(r < 0 || c < 0 || r >= n || c >= n){
        return false;
    }
    if(vis[r][c] == true || ve[r][c] == 0 || ve[r][c] == 1){
        return false;
    }
    // cout << "i " << r << ' ' << c << ' ' << vis[r][c] << endl;
    vis[r][c] = true;
    // cout << "o " << r << ' ' << c << ' ' << vis[r][c] << endl;
    if(ve[r][c] == 2){
        return true;
    }
    return dfs(ve, vis, r + 1, c) || dfs(ve, vis, r - 1, c) || dfs(ve, vis, r, c + 1) || dfs(ve, vis, r, c - 1);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int> > ve(n, vector<int> (n));
        vector<vector<bool> > vis(n, vector<bool> (n, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> ve[i][j];
            }
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout <<  ve[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        bool flag = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(ve[i][j] == 1){
                    flag = dfs(ve, vis, i + 1, j) || dfs(ve, vis, i - 1, j) || dfs(ve, vis, i, j + 1) || dfs(ve, vis, i, j - 1);
                    if(flag)
                        break;
                }
            }
            if(flag)
                break;
        }        
        if(flag)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}