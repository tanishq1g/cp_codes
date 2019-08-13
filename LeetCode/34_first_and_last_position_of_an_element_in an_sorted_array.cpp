#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
    int binarysearch(vector<int> &nums, int in, int la, int target){
        if(in > la)
            return -1;
        int m = (in + la)/2;
        // cout<<m<<'\n';
        if(target == nums[m])
            return m;
        else if(target > nums[m])
            return binarysearch(nums, m+1, la, target);
        else
            return binarysearch(nums, in, m-1, target);
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = nums.size();
        if(s == 0 || s == 1)
            return vector<int> {-1,-1};
        int f = binarysearch(nums, 0, s - 1, target);
        if(f == 1)
            return vector<int> {-1,-1};
        if(f == 0)
            if(nums[f] == nums[f+1])
                return vector<int> {f, f + 1};
            else
                return vector<int> {f, -1};
        if(f == s - 1)
            if(nums[f] == nums[f - 1])
                return vector<int> {f - 1, f};
            else
                return vector<int> {f, -1};
        if(nums[f] == nums[f + 1])
            return vector<int> {f, f + 1};
        if(nums[f] == nums[f - 1])
            return vector<int> {f - 1, f};
        return vector<int> {-1,-1};
    }
};

int main(){
    Solution sol;
    vector<int> nums{4,5,6,7,0,1,2};
    int target = 0;
    cout<<sol.search(nums, target);
}