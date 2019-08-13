#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
    int findsmallest(vector<int>&nums, int in, int la){
        cout<<in<<' '<<la<<'\n';
        if(in > la)
            return -1;
        int m = (la + in) / 2, s = nums.size(), re;
        cout<<m<<'\n';
        if(m == s)
            return -1;
        if(m == 0)
            return -1;
        if(nums[m] < nums[m+1] && nums[m] < nums[m-1])
            return m;
        re = findsmallest(nums, m+1, la);
        if(re != -1)
            return re;
        re = findsmallest(nums, in, m-1);
        if(re != -1)
            return re;
        return -1;
    }
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
    int search(vector<int>& nums, int target) {
        int s = nums.size();
        int fele = findsmallest(nums, 0, s - 1);
        cout<<fele<<'\n';cout<<nums[s-1]<<' '<<target<<'\n';
        if(fele == -1 || fele == 0){
            return binarysearch(nums, 0, s - 1, target);
        }
        else if(target > nums[s - 1]){
            cout<<"in2\n";
            return binarysearch(nums, 0, fele - 1, target);
        }
        else if(target <= nums[s - 1]){
            return binarysearch(nums, fele, s - 1, target);
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector<int> nums{4,5,6,7,0,1,2};
    int target = 0;
    cout<<sol.search(nums, target);
}