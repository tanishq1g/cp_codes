#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int zeroind = -1, s = nums.size(), i = 0, zeroindprev = 0;
        if(s == 0) return false;
        if(s == 1) return true;
        while(i < s){
            cout<<i<<' '<<zeroind<<'\n';
            for (; i < s; i++){
                if(nums[i] == 0){
                    zeroind = i;
                    break;
                }
            }
            if(zeroind == -1) return true;
            for (int j = zeroind - 1; j >= zeroindprev; j--) {
                if(nums[j] + j > zeroind){
                    return true;
                }
            }
            zeroindprev = zeroind;
            i++;
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums{1,0,1,0};
    cout<<sol.canJump(nums);
}