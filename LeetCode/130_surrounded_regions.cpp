#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
class Solution {
    vector<vector<bool> > visited; // for if '0' has been visited
    int sbr, sbc;
public:
    void solve(vector<vector<char>>& board) {
        sbr = board.size();
        if(sbr == 0) return;
        sbc = board[0].size();
        visited = vector<vector<bool> > (sbr, vector<bool> (sbc, false));
        for (int i = 0; i < sbr; i++){
            for (int j = 0; j < sbc; j++){
                // cout<<"in "<<i<<' '<<j<<'\n';
                if(visited[i][j] || board[i][j] == 'X')
                    continue;
                bool surrounded = check(board, i, j);
                if(surrounded){
                    // cout<<"surrounded "<<i<<' '<<j<<'\n';
                    replace(board, i, j);   
                }
            }
        }
                
    }
    
    bool check(vector<vector<char>>& board, int r, int c){
        if(r < 0 || c < 0 || r == sbr || c == sbc) return false;
        if(board[r][c] == 'X' || visited[r][c]) return true;
        visited[r][c] = true;
        bool le = check(board, r, c - 1), ri = check(board, r, c + 1), up = check(board, r - 1, c), dow = check(board, r + 1, c);
        // cout<<"check "<<r<<' '<<c<<' '<<re<<'\n';
        return le&&ri&&up&&dow;
    }

    void replace(vector<vector<char>>& board, int r, int c){
        if(r < 0 || r == sbr || c < 0 || c == sbc || board[r][c] == 'X') return;
        // cout<<"replace "<<r<<' '<<c<<'\n';
        board[r][c] = 'X';
        replace(board, r + 1, c);
        replace(board, r - 1, c);
        replace(board, r, c + 1);
        replace(board, r, c - 1);
    }

};