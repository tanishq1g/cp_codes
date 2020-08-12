// dynamic programming
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();        
        if(n == 0)
            return 0;
        int r = costs[0][0], b = costs[0][1], g = costs[0][2];
        int rr, bb, gg;
        for(int i = 1; i < n; i++){
            rr = min(b + costs[i][0], g + costs[i][0]);
            bb = min(r + costs[i][1], g + costs[i][1]);
            gg = min(r + costs[i][2], b + costs[i][2]);
            r = rr; 
            b = bb; 
            g = gg; 
        }
        return min(r, min(b, g));
    }
};