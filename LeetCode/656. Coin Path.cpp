class Solution {
public:
    vector<int> cheapestJump(vector<int>& ve, int b) {
        int n = ve.size();
        vector<int> ret;
        if(n == 0)
            return ret;
        vector<int> dp(n, INT_MAX);
        vector<int> p(n, -1);
        dp[0] = ve[0];
        int c, ind;
        int lz = 0;
        p[0] = 0;
        for(int i = 0; i < n; i++){
            if(ve[i] == -1){
                continue;
            }
            if(i - 1 >= 0 && ve[i] == 0){
                lz = i;
                if(ve[i - 1] == 0){
                    dp[i] = dp[i - 1];
                    p[i] = i - 1;
                }
                else if(ve[i - 1] == -1){

                }
                else{
                    dp[i] = dp[i - 1];
                    p[i] = p[i - 1];
                }
            }
            // if(i - 1 >= 0 && ve[i - 1] == 0){
            //     dp[i] = dp[i - 1];
            //     p[i] = i - 1;
            // }
            for(int j = 1; j <= b && i + j < n; j++){
                ind = i + j;
                if(ve[ind] == -1){
                    continue;
                }
                c = ve[ind] + dp[i];
                if(p[ind] < lz){
                    dp[ind] = c;
                    p[ind] = i;
                }
                if(dp[ind] > c){
                    dp[ind] = c;
                    p[ind] = i;
                }
                else if(dp[ind] == c && p[ind] < i){
                    dp[ind] = c;
                    p[ind] = i;
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout << dp[i] << ' ';
        } cout << endl;
        for(int i = 0; i < n; i++){
            cout << p[i] << ' ';
        } cout << endl;
        if(dp[n - 1] == INT_MAX)
            return ret;
        for(int i = n - 1; i > 0; ){
            if(p[i] == -1)
                return vector<int> ();
            ret.push_back(p[i] + 1);
            i = p[i];
        }
        reverse(ret.begin(), ret.end());
        ret.push_back(n);
        return ret;
    }
};