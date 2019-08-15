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
        if(f == 1 || f == -1)
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


#define BEGIN 0
#define END 1
#define FIRST true
#define LAST false
class Solution {
public:
    int findOccur(vector<int>& nums, int start, int end, int target, bool firstOrLast) {
        int mid;
        while(start <= end)
        {
            mid = start + (end-start)/2;
            if (nums[mid] == target)
            {
                //Searching for first occurrence (we'll compare with element on left)
                if (firstOrLast == FIRST)
                {
                    if (mid-1 >= 0)
                    {
                        if (nums[mid-1] != target)
                            return mid;
                        //Previous element is equal to target, so continue our search in left half
                        else
                            end = mid-1;
                    }
                    else
                        return mid;
                }
                //Searching for last occurrence (we'll compare with element on the right)
                else
                {
                    if (mid+1 <= end)
                    {
                        if (nums[mid+1] != target)
                            return mid;
                        //Next element is equal to target, so we continue our search in right half
                        else
                            start = mid+1;
                    }
                    else // Reached the end, so return mid
                        return mid;
                }
            }
            else if (nums[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos(2, -1);
        
        if (nums.size() == 0)
            return pos;
        
        int start = 0, end = nums.size()-1;
		//Find the begin and end positions separately
        pos[BEGIN] = findOccur(nums, start, end, target, FIRST);
        pos[END] = findOccur(nums, start, end, target, LAST);
        
        return pos;
    }
};