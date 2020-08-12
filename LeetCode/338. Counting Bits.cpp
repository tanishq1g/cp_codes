
// bits

class Solution {
public:
    vector<int> countBits2(int num) {
        vector<int> ve(num + 1, 0);
        int x;
        for(int i = 1; i <= num; i++){
            x = i;
            while(x > 0){
                if(x & 1)
                    ve[i]++;    
                x = x >> 1;
            }
        }        
        return ve;
    }
    vector<int> countBits(int num) {
        vector<int> ve(num + 1, 0);
        int x;
        for(int i = 1; i <= num; i++){
            ve[i] = ve[i >> 1] + (i & 1);
        }        
        return ve;
    }
};