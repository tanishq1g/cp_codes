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

bool dfsrec(vector<int> g[], vector<int> &ve, vector<bool> &vis, int ind, int parent){

    vis[ind] = true;
    int n = g[ind].size();
    for(int i = 0; i < n; i++){
        if(vis[g[ind][i]] == false){
            if(dfsrec(g, ve, vis, g[ind][i], ind))
                return true;
        }
        else if(g[ind][i] != parent){
            return true;
        }   
    }
    return false;
}

bool isCyclic(vector<int> g[], int V){
    if(V == 0)
        return false;
    vector<int> ve;
    vector<bool> vis(V, false);
    for(int i = 0; i < V; i++){
        if(vis[i] == false){
           if(dfsrec(g, ve, vis, i, i)){
               return true;
           } 
        }
    }
    return false;
}