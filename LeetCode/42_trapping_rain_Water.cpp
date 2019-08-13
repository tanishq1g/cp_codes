#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int highind = 0, highval = 0, vol = 0, highestind = 0;
        int s = height.size();
        if(s == 0 || s == 1)
            return 0;
        // highind = height[0] > height[1] ? 0 : 1;
        // highval = height[highind];
        for (int i = 0; i < s; i++){
            if(height[i] > 0){
                highind = i;
                highval = height[i];
                break;
            }
        }
        for (int i = highind + 1; i < s; i++){
            if(highval <= height[i]){
                highind++;
                while(highind < i){
                    vol += highval - height[highind];
                    cout<<i<<' '<<vol<<'\n';
                    highind++;
                }
                highval = height[i];
            }
        }
        highestind = highind;
        cout<<" highest "<<highestind<<'\n';
        for (int i = s - 1; i >= highestind; i--){
            if(height[i] > 0){
                highind = i;
                highval = height[i];
                break;
            }
        }
        for (int i = highind - 1; i >= highestind; i--){
            if(highval <= height[i]){
                cout<<i<<' '<<highind<<' '<<highval<<'\n';
                highind--;
                while(highind > i){
                    vol += highval - height[highind];
                    cout<<i<<' '<<vol<<'\n';
                    highind--;
                }
                highval = height[i];
            }
        }
        
        return vol;
    }
};

int main(){
    Solution sol;
    vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<sol.trap(nums);
}