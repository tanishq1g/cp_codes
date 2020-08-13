class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ss = s.size();
        vector<int> dp(257, 0);
        int le = 0, count = 0, ma = 0;
        for(int i = 0; i < ss; i++){
            // cout << le << ' ' << i << '\n';
            if(dp[s[i]] == 0){
                count++;
            }
            dp[s[i]]++;
            if(count <= k){
                ma = max(i - le + 1, ma);
            }
            else{
                dp[s[le]]--;
                while(dp[s[le]] != 0){
                    le++;
                    dp[s[le]]--;
                }
                le++;
                count--;
            }
        }        
        return ma;
    }
};