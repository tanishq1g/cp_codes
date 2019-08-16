#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int sn = nums.size();
        if(sn == 0) return 0;
        unordered_set<int> NUMS;
        for (auto n : nums) {
            NUMS.insert(n);
        }
        int ans = 1;
        unordered_set<int> visited;
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited.find(nums[i]) == visited.end()) {
                visited.insert(nums[i]);
                int count = 1;
                int p = nums[i];
                while (NUMS.find(p + 1) != NUMS.end()) {
                    visited.insert(p + 1);
                    count++;
                    p++;
                }
                
                p = nums[i];
                while (NUMS.find(p - 1) != NUMS.end()) {
                    visited.insert(p - 1);
                    count++;
                    p--;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};