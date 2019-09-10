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

class Solution {
    int sr, sc;
public:
    void fill(vector<vector<int>> &rooms, int r, int c, int val){
        if(r < 0 || c < 0 || r == sr || c == sc)
            return;
        if(rooms[r][c] == -1)
            return;
        if(rooms[r][c] < val)
            return;
        rooms[r][c] = val;
        fill(rooms, r + 1, c, val + 1);
        fill(rooms, r - 1, c, val + 1);
        fill(rooms, r, c + 1, val + 1);
        fill(rooms, r, c - 1, val + 1);
    }
    void wallsAndGates(vector<vector<int>> &rooms) {
        sr = rooms.size();
        if(sr == 0)
            return;
        sc = rooms[0].size();
        if(sc == 0)
            return;

        for(int i = 0; i < sr; i++){
            for(int j = 0; j < sc; j++){
                if(rooms[i][j] == 0){
                    fill(rooms, i + 1, j, 1);
                    fill(rooms, i - 1, j, 1);
                    fill(rooms, i, j + 1, 1);
                    fill(rooms, i, j - 1, 1);
                }
            }
        }
    }
};