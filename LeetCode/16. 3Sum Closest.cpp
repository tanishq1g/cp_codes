
// array 3 pointers
class Solution {
public:
    int threeSumClosest(vector<int>& ve, int target) {
        int n = ve.size(), su, diff = INT_MAX;
        sort(ve.begin(), ve.end());
        for(int i = n - 1; i >= 0; i--){
            su = ve[i];
            for(int j = 0, k = i - 1; j < k; ){
                su += ve[j] + ve[k];
                cl = target - su;
                if(abs(diff) > abs(cl)){
                    diff = cl;
                }
                if(su > target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return target - diff;
    }
};