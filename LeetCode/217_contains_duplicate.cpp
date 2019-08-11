#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = true;
            }
            else return true;
        }
        return false;
    }
};