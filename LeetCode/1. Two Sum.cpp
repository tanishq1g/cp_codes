#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// array 

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int x, y, flag = true;
//         map <int, int> m;
//         map <int, int>::iterator it;
//         for (int i = 0; i < nums.size(); i++){
//             // cout << nums[i] << ' ';
//             // cout << m[nums[i]] << ' ' << i << ' '; 
//             it = m.find(target - nums[i]);
//             if(it == m.end()){
//                 cout << "in1 ";
//                 m[nums[i]] = i;
//                 continue;
//             }
//             else{
//                 if(flag){
//                     cout << "in3 ";
//                     x = i;
//                     y = it->second;
//                     flag = false;
//                     it--;
//                     cout << "testing " << it->first << ' ' << it->second << "laolao"; 
//                 }
//                 m[nums[i]] = i;
//             }
//             cout << x << ' ' << y << '\n';
//         }
//         cout << x << ' ' << y;
//         return vector<int> {min(x, y), max(x, y)};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& ve, int target) {
        int n = ve.size();
        vector<int> arr(ve.begin(), ve.end());
        sort(ve.begin(), ve.end());
        int su;
        for(int i = 0, j = n - 1; i < j; ){
            su = ve[i] + ve[j];
            if(su == target){
                int x = distance(arr.begin(), find(arr.begin(), arr.end(), ve[i]));
                int y = distance(arr.begin(), find(arr.begin(), arr.end(), ve[j]));
                if(x == y)
                    y = distance(arr.begin(), find(arr.begin() + x + 1, arr.end(), ve[j]));
                // cout << x << ' ' << y;
                return vector<int> {x, y};
            }    
            else if(su < target){
                i++;
            }
            else{
                j--;
            }
        } 
        return vector<int> {-1, -1};
    }
};
int main() {
	Solution sol;
	vector<int> nums = {1, 2, 3, 1, 0, 6};
	int target = 6; 
	sol.twoSum(nums, target);	
	return 0;
}