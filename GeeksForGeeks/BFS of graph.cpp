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
0 2 1 3 1 4 1 5 2 3 2 8 2 9 3 7 3 9 4 6 4 7 5 6 5 7 5 9 6 8 7 8 7 9

vector <int> bfs(vector<int> g[], int N) {
        
    vector<int> ve;
    if(N == 0)
        return ve;
    vector<bool> vis(N, false); 
    queue<int> q;
    q.push(0);
    vis[0] = true;
    int sq = q.size(), x, sa;
    while(sq != 0){
        for(int i = 0; i < sq; i++){
            x = q.front();
            q.pop();
            // if(vis[x] == true)
            //     continue;
            // vis[x] == true;
            ve.push_back(x);

            sa = g[x].size();
            for(int j = 0; j < sa; j++){
                if(vis[g[x][j]] == false){
                    q.push(g[x][j]);
                    vis[g[x][j]] = true;
                }
            }
        }
        sq = q.size();
    }
    return ve;
}