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

vector <int> dijkstra(vector<vector<int>> g, int src, int V){
    vector<int> ve(V);
    if(V==0)
        return ve;
    vector<bool> vis(V, false);
    int cvis = 0;
    int adjmin, adj;
    g[src][src] = 0;
    vis[src] = true;
    while(cvis < V){
        adjmin = INT_MAX;
        for(int i = 0; i < V; i++){
            if(vis[i] == false && g[src][i] != 0){
                if(adjmin > g[src][i]){
                    adj = i;
                    adjmin = g[src][i]; 
                }
            }
        }
        for(int i = 0; i < V; i++){
            if(g[adj][i] != 0)
            g[src][i] = min(g[src][i], g[src][adj] + g[adj][i]);
        }
        vis[adj] = true;
        cvis++;
    }
    for(int i = 0; i < V; i++){
        ve[i] = g[src][i];
    }
    return ve;
}