class Solution {
public:
    int maxSubArray(vector<int>& ve) {
        int n = ve.size();
        if(n == 0)
            return 0;
        
        int ma = ve[0], su = ve[0], i, le = 0;
        if(su < 0){
            su = 0;
        }
        for(int i = 1; i < n; i++){
            su += ve[i];
            ma = max(ma, su);
            if(su < 0){
                su = 0;
                le = i + 1;
            }
        }
        return ma;
    }
};