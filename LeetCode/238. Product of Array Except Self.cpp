class Solution {
public:
    vector<int> productExceptSelf(vector<int>& ve) {
        int n = ve.size();
        vector<int> p(n);
        long long int pr = 1;
        int c = 0;
        
        for(int i = 0; i < n; i++){
            if(ve[i] == 0){
                c++;
                continue;
            }
            pr *= ve[i];   
        }
        for(int i = 0; i < n; i++){
            if(ve[i] == 0){
                if(c > 1)
                    p[i] = 0;
                else
                    p[i] = pr;
            }
            else{
                if(c > 0)
                    p[i] = 0;
                else
                    p[i] = pr / ve[i];   
            }
        }
        return p;
    }
};