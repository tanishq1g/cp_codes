// dynamic programming

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();        
        if(n == 0)
            return 0;
        int k = costs[0].size();
        vector<int> ve = costs[0];
        vector<int> ve2 = ve;
        int mi;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < k; j++){
                mi = INT_MAX;
                for(int p = 0; p < k; p++){
                    if(p == j)
                        continue;
                    mi = min(mi, ve[p]);
                } 
                ve2[j] = mi + costs[i][j];
            }
            ve = ve2;
        }
        mi = INT_MAX;
        for(int i = 0; i < k; i++){
            mi = min(mi, ve[i]);    
        }
        return mi;
    }
};