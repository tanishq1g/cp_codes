#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
// dynamic programming
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int highind = 0, highval = 0, vol = 0, highestind = 0;
//         int s = height.size();
//         if(s == 0 || s == 1)
//             return 0;
//         // highind = height[0] > height[1] ? 0 : 1;
//         // highval = height[highind];
//         for (int i = 0; i < s; i++){
//             if(height[i] > 0){
//                 highind = i;
//                 highval = height[i];
//                 break;
//             }
//         }
//         for (int i = highind + 1; i < s; i++){
//             if(highval <= height[i]){
//                 highind++;
//                 while(highind < i){
//                     vol += highval - height[highind];
//                     cout<<i<<' '<<vol<<'\n';
//                     highind++;
//                 }
//                 highval = height[i];
//             }
//         }
//         highestind = highind;
//         cout<<" highest "<<highestind<<'\n';
//         for (int i = s - 1; i >= highestind; i--){
//             if(height[i] > 0){
//                 highind = i;
//                 highval = height[i];
//                 break;
//             }
//         }
//         for (int i = highind - 1; i >= highestind; i--){
//             if(highval <= height[i]){
//                 cout<<i<<' '<<highind<<' '<<highval<<'\n';
//                 highind--;
//                 while(highind > i){
//                     vol += highval - height[highind];
//                     cout<<i<<' '<<vol<<'\n';
//                     highind--;
//                 }
//                 highval = height[i];
//             }
//         }
        
//         return vol;
//     }
// };


class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        if(size == 0)
            return 0;
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<sol.trap(nums);
}