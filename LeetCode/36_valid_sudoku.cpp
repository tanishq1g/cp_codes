#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int no, bc, br, bb, rr, rc;
        vector<vector<bool> > blocks(10, vector<bool> (11, false));
        vector<vector<bool> > rows(10, vector<bool> (11, false));
        vector<vector<bool> > cols(10, vector<bool> (11, false));
        for (int i = 0; i < 9; i++){
            br = i/3; rr = i;
            for (int j = 0; j < 9; j++){
                if(board[i][j] == '.')
                    continue;
                rc = j;
                no = board[i][j] - 48;
                bc = j/3;
                bb = 3 * br + bc;
                if(blocks[bb][no] || rows[rr][no] || cols[rc][no])
                    return false;
                rows[rr][no] = true;
                cols[rc][no] = true;
                blocks[bb][no] = true;
            }
        }
        return true;
    }
};
