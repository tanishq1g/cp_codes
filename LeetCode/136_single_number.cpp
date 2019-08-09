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
    // hashing
    // int singleNumber(vector<int>& nums) {
    //     map<int, int> m;
    //     map<int, int>::iterator it;
    //     for (int i = 0; i < nums.size(); i++){
    //         it = m.find(nums[i]);
    //         if(it == m.end())
    //             m[nums[i]] = 1;
    //         else
    //             m.erase(nums[i]);
    //     }
    //     return m.begin()->first;
    // }

    // XOR
    int singleNumber(vector<int>& nums) {
        int r;
        for (int i = 0; i < nums.size(); i++){
            r = r ^ nums[i];
        }
        return r;
    }
};

int main(){
    vector<int> nums{2,2,1};
    Solution sol;
    cout<<sol.singleNumber(nums);
    return 0;
}