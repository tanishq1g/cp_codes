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

void dfs(vector<int> adj[], vector<bool> &vis, stack<int> &st, int ind){
    vis[ind] = true;
    
    int sadj = adj[ind].size();
    for(int i = 0; i < sadj; i++){
        if(vis[adj[ind][i]] == false){
            dfs(adj, vis, st, adj[ind][i]);
        }
    }
    st.push(ind);
}

void dfs2(vector<int> adj[], vector<bool> &vis, int ind){
    vis[ind] = true;
    
    int sadj = adj[ind].size();
    for(int i = 0; i < sadj; i++){
        if(vis[adj[ind][i]] == false){
            dfs2(adj, vis, adj[ind][i]);
        }
    }
    // st.push(ind);
}

int kosaraju(int V, vector<int> adj[]){
    if(V==0)
        return 0;
    
    vector<bool> vis(V, false);
    stack<int> st;

    for(int i = 0; i < V; i++){
        if(vis[i] == false){
            dfs(adj, vis, st, i);
        }
    }

    vis = vector<bool> (V, false);

    vector<int> adj2[V];
    int sadj;
    for(int i = 0; i < V; i++){
        sadj = adj[i].size();
        for(int j = 0; j < sadj; j++){
            adj2[adj[i][j]].push_back(i);
        }
    }
    delete adj;
    int count = 0;
    while(!st.empty()){
        int i = st.top();
        st.pop();
        if(vis[i] == false){
            dfs2(adj2, vis, i);
            count++;
        }
    }
    return count;
}