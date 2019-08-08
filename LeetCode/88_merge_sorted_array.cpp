#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;


void printvector(vector<int> &a){
    for (size_t i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<' ';
    }
    cout << '\n';
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m --;
        n --;
        while((m >= 0) & (n >= 0)){
            if(nums1[m] > nums2[n]){
                nums1[m + n + 1] = nums1[m];
                m--;
            }
            else{
                nums1[m + n + 1] = nums2[n];
                n--;
            }
        }
        if(n >= 0){
            for (size_t i = 0; i <= n; i++){
                nums1[i] = nums2[i];
            }
        }
        printvector(nums1);
    }
};

int main(){
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};
    Solution sol;
    sol.merge(nums1, nums1.size(), nums2, nums2.size());
    return 0;
}