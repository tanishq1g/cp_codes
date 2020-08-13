// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) {
        
//         vector<int> temp = nums;
//         sort(temp.begin(), temp.end());
        
//         int i = (temp.size()-1)/2;
//         int j = temp.size()-1;
//         int k = 0;
//         while(k < nums.size())
//         {
//             if(k&1)
//                 nums[k++] = temp[j--];
//             else
//                 nums[k++] = temp[i--];
//         }
//     }
// };


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        threeWayPartition(nums, nums[mid]);
        vector<int> res(n);
        int largeStart = n-1;
        int smallStart = (n%2) ? mid : (mid-1);
        for (int i = 0; i < n; i+=2)
            res[i] = nums[smallStart--];
        for (int i = 1; i < n; i+=2)
            res[i] = nums[largeStart--];
        nums = res;
    }
    
    // this ensures all values equal to the median is in the middle
    void threeWayPartition(vector<int> &nums, int val) {
        int i = 0, j = 0;
        int n = nums.size()-1;
        while (j <= n){
            if (nums[j] < val)
                swap(nums[i++], nums[j++]);
            else if (nums[j] > val)
                swap(nums[j], nums[n--]);
            else
                j++;
        }
    }
};