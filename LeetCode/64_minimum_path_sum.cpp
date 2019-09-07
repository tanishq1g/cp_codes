class Solution {
    // DYNAMIC PROGRAMMING
public:
    int minPathSum(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();


        // Filling the values for the first column
        for (int i = 1; i < R; i++) {
            grid[i][0] +=  grid[i-1][0];
        }

        // Filling the values for the first row
        for (int i = 1; i < C; i++) {
            grid[0][i] += grid[0][i-1];
        }

    
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                    grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }

        // Return value stored in rightmost bottommost cell. That is the destination.
        return grid[R - 1][C - 1];
    }
};
