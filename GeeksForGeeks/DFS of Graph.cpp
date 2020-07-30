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

void dfsrec(vector<int> g[], vector<int> &ve, vector<bool> &vis, int ind){
    if(vis[ind] == true)
        return;
    ve.push_back(ind);
    vis[ind] = true;
    int n = g[ind].size();
    for(int i = 0; i < n; i++){
        if(vis[g[ind][i]] == false){
            dfsrec(g, ve, vis, g[ind][i]);
        }   
    }
}

vector <int> dfs(vector<int> g[], int N){
    vector<int> ve;
    vector<bool> vis(N, false);
    dfsrec(g, ve, vis, 0);
    return ve;
}