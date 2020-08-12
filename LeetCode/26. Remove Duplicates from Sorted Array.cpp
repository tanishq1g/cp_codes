// array

class Solution {
public:
    int removeDuplicates(vector<int>& ve) {
        int n = ve.size(), i, j;
        for(i = 0, j = 0; i < n; ){
            while(i > 0 && ve[i] == ve[i - 1] && i < n){
                i++;
            }
            // cout << j << ' ' << i << '\n';
            if(i == n){
                ve[j] = ve[i - 1];
                j++;
                break;
            }
            ve[j] = ve[i];
            j++;
            i++;
        }       
        return j;
    }
};