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

void dfs(vector<int> adj[], vector<int> &ve, vector<bool> &vis, int ind){
    vis[ind] = true;
    int sadj = adj[ind].size();
    for(int i = 0; i < sadj; i++){
        if(vis[adj[ind][i]] == false){
            dfs(adj, ve, vis, adj[ind][i]);
        }
    }
    ve.push_back(ind);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> ve;
    if(V==0)
        return ve;
    vector<bool> vis(V, false);
    for(int i = 0; i < V; i++){
        if(vis[i] == false)
            dfs(adj, ve, vis, i);
    }
    reverse(ve.begin(), ve.end());
    return ve;
}