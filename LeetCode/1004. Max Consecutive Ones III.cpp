class Solution {
public:
    int longestOnes(vector<int>& ve, int k) {
        int n = ve.size();
        int le = 0, ck = k, ma = 0;
        for(int i = 0; i < n; i++){
            if(ve[i] == 1){
                ma = max(i - le + 1, ma);
            }
            else{
                if(k == 0){
                    while(ve[le] == 1){
                        le++;
                    }
                    le++;
                    continue;
                }
                if(ck == 0){
                    while(ck == 0){
                        if(ve[le] == 0){
                            ck++;
                        }
                        le++;
                    }
                    ck--;
                }
                else{
                    ck--;
                    ma = max(i - le + 1, ma);
                }
            }
            cout << le << ' ' << i << ' ' << ma << ' ' << ck << '\n';
        }
        return ma;
    }
};