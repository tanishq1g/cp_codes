#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > re;
        vector<int> temp;
        int s = nums.size();
        long no = (1 << s) - 1;
        while(no >= 0){
            for (int i = 0; i < s; i++){
                if(no >> i & 1)
                    temp.push_back(nums[i])
            }
            re.push_back(temp);
            no--;
        }
        return re;
    }
};