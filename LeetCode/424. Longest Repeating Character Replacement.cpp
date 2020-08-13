class Solution {
public:
    int characterReplacement(string s, int k) {
        int ss = s.size();
        if(ss == 0)
            return 0;
        int ck = k;
        int le = 0, ma = 0;
        char c = s[0];
        for(int i = 1; i < ss; i++){
            // cout << le << ' ' << i << ' ' << c << ' ' << ma << ' ' << ck << '\n';
            if(s[i] == c){
                ma = max(ma, i - le + 1);
            }
            else{
                if(ck == 0){
                    le++;
                    ck = k;
                    while(s[le] == c){
                        le++;
                    }
                    c = s[le];
                    i = le;
                }
                else{
                    ck--;
                    ma = max(ma, i - le + 1);
                }
            }
        }

        if(ss > 1 && k > 0){
            le = 0;
            ck = k - 1;
            c = s[1];
            for(int i = 2; i < ss; i++){
                // cout << le << ' ' << i << ' ' << c << ' ' << ma << ' ' << ck << '\n';
            if(s[i] == c){
                ma = max(ma, i - le + 1);
            }
            else{
                if(ck == 0){
                    break;
                }
                else{
                    ck--;
                    ma = max(ma, i - le + 1);
                }
            }
            }
        }
        le = ss - 1; 
        c = s[ss - 1];
        ck = k;
        // for(int i = ss - 2; i >= 0; i--){
        //     cout << le << ' ' << i << ' ' << c << ' ' << ck << '\n';
        //     if(s[i] == c){
        //         ma = max(ma, le - i + 1);
        //     }
        //     else{
        //         if(ck == 0){
        //             le--;
        //             ck = k;
        //             while(s[le] != c && le >= 0){
        //                 le--;
        //             }
        //             c = s[le];
        //             i = le;
        //         }
        //         else{
        //             ck--;
        //             ma = max(ma, le - i + 1);
        //         }
        //     }
        // }
        return ma;
    }
};