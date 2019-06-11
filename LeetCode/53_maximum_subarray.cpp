#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msum = INT_MIN;
        int sum = 0;
        int lin = 0, rin = 0;
        int lsum = 0;
        int flag = false;
        for (size_t i = 0; i < nums.size(); i++){
            // cout << i << ' ' << nums[i];
            sum += nums[i];
            if(nums[i] == 0){
                msum = 0;
            }
            if(sum < 0){
                msum = max(msum, sum);
            }
            if(sum <= 0){
                sum = 0;
                lin = i + 1;
                rin = i + 1;
            }
            else{
                if(lsum < sum){
                    lsum = sum;
                }
                rin++;
            }
            // cout << ' '<<sum << ' '<<lin << ' '<<rin << ' '<<msum<<'\n';
        }
        if(lsum == 0 && flag)
            return msum;
        return lsum;
    }

    int maxSubArrayDP(vector<int>& nums) {
        int sum = 0, smax = INT_MIN;
        for (int num : nums) {
            sum += num;
            smax = max(smax, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return smax;
    }

    int divideandconquer(vector<int>&nums, int l, int r){
        cout << l << ' '<<r<<'\n';
        // if(l > r)
        //     return INT_MIN;
        if(l == r)
            return nums[l];
        int m = (l + r) / 2;
        int lmax = divideandconquer(nums, l, m);
        int rmax = divideandconquer(nums, m + 1, r);

        // go left from mid
        int sum = 0, lm = 0, rm = 0;
        for (int i = m; i >= l; i--){
            sum += nums[i];
            lm = max(sum, lm);
        }

        // go right from mid
        sum = 0;
        for (int i = m + 1; i <= r; i++){
            sum += nums[i];
            rm = max(sum, rm);
        }
        cout << "out "<<lmax << ' ' << rmax << ' ' << lm << ' ' << rm << '\n';
        return max(max(lmax, rmax), lm + rm );
    }

    int maxSubArraydc(vector<int>& nums) {
        return divideandconquer(nums, 0, nums.size() - 1);
    }

};

void main(){
    // vector<int> nums = {-1, 0};
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    cout << sol.maxSubArraydc(nums);
}   