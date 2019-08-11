#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
// TWO POINTER
    int maxArea(vector<int>& height) {
        int s = height.size(), in = 0, la = s - 1, vol = 0;
        while(in <= la){
            cout<<in<<' '<<la<<' '<<vol<<'\n';
            vol = max(vol, min(height[in], height[la]) * (la - in));
            if(height[in] > height[la]){
                la--;
            }
            else{
                in++;
            }
            // if(height[la] > height[in+1] && height[in] > height[la-1]){
            //     if(height[in+1] > height[la-1]) la--;
            //     else in++;
            // }
            // else if(height[in] > height[la-1]) in++;
            // else if(height[in+1] > height[la]) ;
        }
        return vol;
    }
};


int main(){
    Solution sol;
    vector<int> h{10,14,10,4,10,2,6,1,6,12};
    cout<<sol.maxArea(h);
    return 0;
}
