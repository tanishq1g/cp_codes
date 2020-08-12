// array

class Solution {
public:
    void nextPermutation(vector<int>& ve) {
        int n = ve.size(), i;
        if(n == 0 || n == 1)
            return;
        for(i = n - 2; i >= 0; i--){
            if(ve[i] < ve[i + 1]){
                break;
            }
        }
        if(i < 0){
            reverse(ve.begin(), ve.end());
        }
        else{
            int ind, cl = INT_MAX;
            for(int j = i + 1; j < n; j++){
                if(ve[j] > ve[i]){
                    if(cl >= ve[j] - ve[i]){
                        cl = ve[j] - ve[i];
                        ind = j;
                    }
                }
            }
            swap(ve[ind], ve[i]);
            reverse(ve.begin() + i + 1, ve.end());
        }
    }
};