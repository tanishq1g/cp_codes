#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size())
            return 0;
        int j = 0;
        for (int i = 1; i < nums.size(); i++){
            if(nums[j] != nums[i]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};

void main(){

}