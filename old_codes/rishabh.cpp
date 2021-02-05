#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

int maxbeauty;

// 0 -> 1
// tb - b[0] 
// tt - t(0,3)

void dfs(vector<vector<pair<int, int> > > &gr, vector<int> &beauty, vector<bool> &vis, int &maxt, int &tb, int &tt, int cur){
    vis[cur] = true;
    int scur = gr[cur].size();
    tb += beauty[cur];
    maxbeauty = max(maxbeauty, tb);

    for (size_t i = 0; i < scur; i++){
        if(vis[gr[cur][i]] == true)
            continue;
        tt += gr[cur][i].second;
        if(2 * tt > maxt){
            tt -= gr[cur][i].second;
            continue;
        }
        dfs(gr, beauty, vis, maxt, tb, tt, gr[cur][i].first);
        tt -= gr[cur][i].second;
    }
    
    tb -= beauty[cur];
}

int main(){
    int n, m, maxt;
    cin >> n >> m >> maxt;
    vector<int> beauty(n), u(m), v(m), t(m);
    for (size_t i = 0; i < n; i++){
        cin >> beauty[i];
    }
    for (size_t i = 0; i < m; i++){
        cin >> u[i];
    }
    for (size_t i = 0; i < m; i++){
        cin >> v[i];
    }
    for (size_t i = 0; i < m; i++){
        cin >> t[i];
    }

    // n = 4
    // 3
    // 30
    // 5 10 15 50
    // u - 0 1 0
    // v - 1 2 3
    // t - 6 7 10
    vector<vector<pair<int, int> > > gr(n, vector<pair<int, int> > ());
    // 0 - (1,6), (3,10)
    // 1 - (0,6), (2,7)
    // 2 - (1,7)
    // 3 - 
    for (size_t i = 0; i < m; i++){
        gr[u[i]].push_back(pair<int, int> (v[i], t[i]));
        gr[v[i]].push_back(pair<int, int> (u[i], t[i]));
    }

    vector<bool> vis(n, false);
    maxbeauty = INT_MIN;

    int total_beauty = 0, total_time = 0; 
    
    dfs(gr, beauty, vis, maxt, total_beauty, total_time, 0);

    cout << maxbeauty;
    return 0;
}
 