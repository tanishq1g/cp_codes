// array three pointers

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& ve, int target) {
        int n = ve.size(), su;
        vector<vector<int> > ret; 
        sort(ve.begin(), ve.end());
        for(int i = n - 1; i >= 3; i--){
            while(i + 1 < n && i >= 0 && ve[i] == ve[i + 1])
                i--;
            for(int j = i - 1; j >= 2; j--){
                while(j + 1 < i && j >= 0 && ve[j] == ve[j + 1])
                    j--;
                for(int p = 0, q = j - 1; p < q; ){
                    su = ve[i] + ve[j] + ve[p] + ve[q];
                    if(su == target){
                        ret.push_back(vector<int> {ve[p], ve[q], ve[j], ve[i]});
                        p++;
                        while(p - 1 >= 0 && p < q && ve[p] == ve[p - 1]){
                            p++;
                        }
                    }
                    else if(su < target){
                        p++;
                        while(p - 1 >= 0 && p < q && ve[p] == ve[p - 1]){
                            p++;
                        }
                    }
                    else{
                        q--;
                        while(q + 1 < j && q >= 0 && ve[q] == ve[q + 1]){
                            q--;
                        }
                    }
                }
            }
        }
        return ret;
    }
};