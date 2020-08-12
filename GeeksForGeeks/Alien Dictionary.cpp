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
#define INF 1e7
// GRAPH

void dfs(vector<vector<int> > &g, string &ret, vector<bool> &vis, int ind){
    vis[ind] = true;
    int s = g[ind].size();
    for(int i = 0; i < s; i++){
        if(vis[g[ind][i]] == false){
            dfs(g, ret, vis, g[ind][i]);
        }
    }
    ret += char(ind + 'a');
}

string findOrder(string dict[], int n, int k) {
    vector<vector<int> > g(k, vector<int>());
    int miind;
    string ret = "";
    for(int i = 1; i < n; i++){
        miind = min(dict[i].size(), dict[i - 1].size());
        for(int j = 0; j < miind; j++){
            if(dict[i][j] != dict[i- 1][j]){
                g[dict[i - 1][j] - 'a'].push_back(dict[i][j] - 'a');
                // cout << miind << ' ' <<dict[i - 1][j] - 'a' << ' ' << dict[i][j] - 'a' << '\n';
                break;
            }
        }
    }
    vector<bool> vis(k, false);
    for(int i = 0; i < k; i++){
        if(vis[i] == false){
            dfs(g, ret, vis, i);
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}