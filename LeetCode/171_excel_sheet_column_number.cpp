class Solution {
public:
    int titleToNumber(string s) {
        int r = 0;
        int l = s.size();
        if(l == 0) return 0;
        for (int i = 0; i < l ; i++){
            r += pow(26,l-i-1) * (s[i] - 64);
        }
        return r;
    }
};