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

bool dfsrec(vector<int> adj[], vector<bool> &vis, vector<bool> &recvis, int ind){
    vis[ind] = true;
    recvis[ind] = true;
    int sadj = adj[ind].size();
    for(int i = 0; i < sadj; i++){
        if(vis[adj[ind][i]] == false){
            if(dfsrec(adj, vis, recvis, adj[ind][i]))   
                return true;
        } 
        else if(recvis[adj[ind][i]] == true){
            return true;
        }
    }
    recvis[ind] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[]){
    if(V == 0)
        return false;
    vector<bool> vis(V, false), recvis(V, false);
    for(int i = 0; i < V; i++){
        if(dfsrec(adj, vis, recvis, i))
            return true;
    }
    return false;
}