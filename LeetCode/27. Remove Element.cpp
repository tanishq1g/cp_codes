// array
class Solution {
public:
    int removeElement(vector<int>& ve, int val) {
        int n = ve.size(), i, j;       
        for(i = 0, j = 0; i < n; i++){
            if(ve[i] == val){
                continue;
            }
            ve[j] = ve[i];
            j++;
        }
        return j;
    }
};