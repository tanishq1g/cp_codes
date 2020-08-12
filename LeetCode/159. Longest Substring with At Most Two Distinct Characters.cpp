class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();       
        if(n == 0 || n == 1)
            return n;
        int ma = INT_MIN, le = 0;
        vector<int> dp(130, 0);
        int d = 0;
        int c;
        for(int i = 0; i < n; i++){
            c = s[i];
            dp[c]++;
            if(dp[c] == 1){
                d++;
            }
            if(d <= 2){
                ma = max(ma, i - le + 1);
            }
            while(d > 2){
                c = s[le];
                dp[c]--;
                if(dp[c] == 0)
                    d--;
                le++;
            }
            cout << le << ' ' << i << ' ' << ma << '\n';
        }
        return max(0, ma);
    }
};