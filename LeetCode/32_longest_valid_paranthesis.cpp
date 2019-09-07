
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    // dynamic programming
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(),0);
        int res = 0;
        for(int i=1; i<s.length(); ++i)
            if(s[i]==')' && i-1-dp[i-1]>=0 &&s[i-1-dp[i-1]]=='('){
                if(i-1-dp[i-1]-1 >= 0) dp[i]= dp[i-1]+2+dp[i-1-dp[i-1]-1];
                else  dp[i]= dp[i-1]+2;
                res = max(res, dp[i]);
            }
        return res;
    }

};

int main(){
    Solution sol;
    cout<<sol.longestValidParentheses("(()");

    return 0;
}