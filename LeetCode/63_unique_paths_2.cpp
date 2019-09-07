class Solution {
public:
// Dynamic Programming
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int xdim = obstacleGrid.size();
        if(xdim == 0)
            return 0;
        int ydim = obstacleGrid[0].size();
        
        vector<vector<unsigned long long int>> DP(xdim, vector<unsigned long long int>(ydim, 0));
        if(obstacleGrid[0][0] == 1)
            DP[0][0] = 0;
        else
            DP[0][0]=1;
        
        for(int i = 1; i<xdim; i++){
            if(obstacleGrid[i][0] == 1)
                DP[i][0] = 0;
            else
                DP[i][0] = DP[i-1][0];
        }
        for(int j =1; j<ydim; j++){
            if(obstacleGrid[0][j] == 1)
                DP[0][j] = 0;
            else
                DP[0][j] = DP[0][j-1];
        }

        for(int i=1; i<xdim; i++){
            for(int j=1;j<ydim;j++){
                if(obstacleGrid[i][j] == 1)
                    DP[i][j] = 0;
                else
                    DP[i][j] = DP[i][j-1] + DP[i-1][j];
            }
        }
        return DP[xdim-1][ydim-1];
    }
};