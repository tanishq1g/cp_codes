// array
class Solution {
public:
    int removeDuplicates(vector<int>& ve) {
        int n = ve.size(), i, j;
        if(n == 0)
            return 0;

        int lcnt = 1, lval = ve[0];
        for(i = 1, j = 1; i < n; i++){
            cout << i << ' ' << j << '\n';
            if(ve[i] == lval){
                if(lcnt <= 2){
                    ve[j] = ve[i];
                    j++;
                }
                lcnt++;
                continue;
            }
            ve[j] = ve[i];
            lval = ve[i];
            lcnt = 1;
            j++;
        }
        return j;
    }
};