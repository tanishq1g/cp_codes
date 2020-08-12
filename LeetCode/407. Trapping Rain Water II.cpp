
class Solution {
    // pair<int, int> findlarge(vector<vector<int>> &hm, int r, int c, int &cur){

    // }
public:
    int trapRainWater(vector<vector<int>>& hm) {
        int sr = hm.size();
        if(sr == 0)
            return 0;
        int sc = hm[0].size();
        int minsr;
        int up, lo, le, ri;
        long long int vol = 0;
        int mi;
        
        int y = 8;
        while(y--){
        for(int i = 1; i < sr - 1; i++){
            for(int j = 1; j < sc - 1; j++){
                up = -1; lo = -1; le = -1; ri = -1;
                
                for(int k = i - 1; k >= 0; k--){
                    if(hm[k][j] > hm[i][j]){
                        up = hm[k][j];
                        break;
                    }
                }
                for(int k = i + 1; k < sr; k++){
                    if(hm[k][j] > hm[i][j]){
                        lo = hm[k][j];
                        break;
                    }
                }
                for(int k = j - 1; k >= 0; k--){
                    if(hm[i][k] > hm[i][j]){
                        le = hm[i][k];
                        break;
                    }
                }
                for(int k = j + 1; k < sc; k++){
                    if(hm[i][k] > hm[i][j]){
                        ri = hm[i][k];
                        break;
                    }
                }
                // cout<<"i "<<i<<" j "<<j<<" val "<<hm[i][j]<<" up "<<up<<" lo "<<lo<<" le "<<le<<" ri "<<ri<<'\n';

                if(up == -1 || lo == -1 || le == -1 || ri == -1){
                    continue;
                }
                else{
                    mi = min(up, min(lo, min(le, ri)));
                    vol += mi - hm[i][j];
                    hm[i][j] = mi;
                }
                // cout<<vol<<'\n';

            }
        }}
        return vol;
    }
};