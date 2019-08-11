#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
// DP dynamic programming
    int rob(vector<int>& nums) {
        int s = nums.size();
        if(s == 0) return 0;
        if(s == 1) return nums[0];
        if(s == 2) return max(nums[0], nums[1]);
        vector<int> dp(s);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < s; i++){
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
         return dp[s-1];
    }
};