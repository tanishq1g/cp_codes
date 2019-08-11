#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int s = nums.size(), sum, val, flag = 0;
    //     vector<int> temp(3);
    //     vector<vector<int> > re;
    //     for(int i = 0; i < s-2; i++){
    //         unordered_map<int, int> m;
    //         sum = -nums[i];
    //         for(int j = i+1; j < s; j++){
    //             val = sum - nums[j];
    //             if(m.find(val) != m.end()){
    //                 if((m[val] != i  && m[val] != j)){
    //                     // cout<<i<<' '<<j<<' '<<sum<<' '<<val<<'\n';
    //                     temp[0] = nums[i]; temp[1] = nums[j]; temp[2] = val;
    //                     sort(temp.begin(), temp.end());
    //                     for(int k = 0; k < re.size(); k++){
    //                         if(re[k][0] == temp[0] && re[k][1] == temp[1] && re[k][2] == temp[2])
    //                             flag = 1;
    //                     }
    //                     if(!flag)
    //                         re.push_back(temp);
    //                     flag = 0;
    //                 }
    //             }
    //             m[nums[j]] = j;
    //             // else{
    //             // }
    //         }
    //     }
    //     return re;
    // }

// TWO POINTER
    vector<vector<int>> threeSum(vector<int>& nums) {
        int s = nums.size(), sum, val, flag = 0, j,k;
        vector<int> temp(3);
        vector<vector<int> > re;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < s-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; // avoid duplicate from first value;
            if(nums[i] + nums[i+1] + nums[i+2] > 0) break; //no solution 
            if(nums[i] + nums[s-1] + nums[s-2] < 0) continue; //i is too small

            j = i + 1; k = s-1;
            
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) k--;
                else if(sum < 0) j++;
                else{
                    re.push_back(vector<int> {nums[i], nums[j], nums[k]});
                    do{
                        j++;
                    }while(nums[j] == nums[j-1] && j < k);  //duplicate through second value
                    do{
                        k--;
                    }while(nums[k] == nums[k+1] && j < k);  //duplicate through third value
                }
            }
        }
        return re;
    }
};

int main(){
    Solution sol;
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int> > re;
    re = sol.threeSum(nums);
    for(int i = 0; i < re.size(); i++){
        for(int j = 0; j < re[i].size(); j++){
            cout<<re[i][j]<<' ';
        }
        cout<<'\n';
    }
}