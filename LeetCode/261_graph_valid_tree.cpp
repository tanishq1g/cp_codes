#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution{
    bool dfs(vector<vector<int>> &al, int u, vector<bool> &vis, vector<bool> &path){
        vis[u] = true;
        path[u] = true;
        for(auto x : al[u]){
            if(path[x])
                return true;
            if(vis[x] == false){
                if(dfs(g, vis, vis, path))
                    return true;
            }
        }
        path[u] = false;
        return false;
    }
public:
    bool checkCycle(int n, vector<vector<int> al){
        vector<bool> vis(numCourses, false);
        vector<bool> path(numCourses, false);
        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                if(dfs(al, i, vis, path))
                    return false;
            }
        }
        return true;
    }
};
