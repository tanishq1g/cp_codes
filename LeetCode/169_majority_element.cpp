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
// SORTING SOLUTION
    int majorityElement(vector<int>& nums) {
        int s = nums.size();
        sort(nums.begin(), nums.end());
        return nums[s/2];
    }

// METHOD 3 (Using Moore’s Voting Algorithm)
// This is a two step process.

// NOTE : This Method only works when we are given that majority element do exist in the array , otherwise this method won’t work , as in the problem definition we said that majority element may or may not exist but for applying this approach you can assume that majority element do exist in the given input array

// The first step gives the element that may be majority element in the array. If there is a majority element in an array, then this step will definitely return majority element, otherwise it will return candidate for majority element.
// Check if the element obtained from above step is majority element.This step is necessary as we are not always sure that element return by first step is majority element.
    int majorityElement(vector<int>& nums) {
        int maj_ind = 0, count = 1;
        for (int i = 1; i < nums.size(); i++){
            if(nums[maj_ind] == nums[i])
                count++;
            else
                count--;
            if(count == 0){
                maj_ind = i;
                count == 1;
            }
        }
        return a[maj_ind];
    }
};