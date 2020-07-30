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

void dfs(vector<int> a[], vector<vector<bool> > &vis, int N, int M, int r, int c){
    if(r < 0 || c < 0 || r >= N || c >= M)
        return;
    if(vis[r][c] == true)
        return;
    if(a[r][c] == 0)
        return;
    vis[r][c] = true;
    dfs(a, vis, N, M, r + 1, c);
    dfs(a, vis, N, M, r + 1, c - 1);
    dfs(a, vis, N, M, r + 1, c + 1);
    dfs(a, vis, N, M, r - 1, c);
    dfs(a, vis, N, M, r - 1, c - 1);
    dfs(a, vis, N, M, r - 1, c + 1);
    dfs(a, vis, N, M, r, c - 1);
    dfs(a, vis, N, M, r, c + 1);
}

int findIslands(vector<int> a[], int N, int M) {
    vector<vector<bool> > vis(N, vector<bool>(M, false));
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] != 0 && vis[i][j] == false){
                dfs(a, vis, N, M, i, j);
                count++;
            }
        }
    }
    return count;
}