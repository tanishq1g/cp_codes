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


int n, m, x, y, msteps;
void dfs(vector<vector<int> > &ve, vector<vector<bool> > &vis, int r, int c, int steps){
    if(r < 0 || c < 0 || r >= n || c >= m){
        return ;
    }
    if(vis[r][c] == true || ve[r][c] == 0)
        return ;
    // cout << r << ' ' << c << ' ' << steps << endl;
    if(r == x && c == y){
        msteps = min(msteps, steps);
        return;
    }
    vis[r][c] = true;
    dfs(ve, vis, r + 1, c, steps + 1);
    dfs(ve, vis, r - 1, c, steps + 1);
    dfs(ve, vis, r, c + 1, steps + 1);
    dfs(ve, vis, r, c - 1, steps + 1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int> > ve(n, vector<int> (m));
        vector<vector<bool> > vis(n, vector<bool> (m, false));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> ve[i][j];
            }
        } 
        cin >> x >> y;

        msteps = INT_MAX;
        dfs(ve, vis, 0, 0, 0);
        if(msteps == INT_MAX){
            cout << -1 << endl;
        }
        else
            cout << msteps << endl;
    }
    return 0;
}