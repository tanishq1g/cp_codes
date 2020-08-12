// array

class Solution { 
public:
    void moveZeroes(vector<int>& ve) {
        int n = ve.size(), i, cur;
        for(i = 0, cur = 0; i < n; i++){
            if(ve[i] == 0){
                continue;
            }
            ve[cur] = ve[i];
            cur++;
        }
        for(int i = cur; i < n; i++){
            ve[cur] = 0;
        }
    }
};