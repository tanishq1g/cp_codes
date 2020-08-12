
// array

class Solution {
public:
    int threeSumSmaller(vector<int>& ve, int target) {
        int n = ve.size();        
        sort(ve.begin(), ve.end());
        int su;
        vector<vector<int> > ret;
        int count = 0, x;
        for(int i = n - 1; i >= 0; i--){
            x = target - ve[i];
            for(int j = 0, k = i - 1; j < k;){
                su = ve[j] + ve[k];
                if(su == x){
                    k--;
                }
                else if(su > x){
                    k--;
                }
                else{
                    cout << j << ' ' << k << ' ' << i<< '\n';
                    count += (k - j);
                    j++;
                }
            }
        }
        return count;
    }
};