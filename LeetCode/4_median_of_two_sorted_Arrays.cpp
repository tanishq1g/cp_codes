#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        int s = s1 + s2;
        double ele;
        int m = (s) / 2, i, j;
        if(s%2 == 0) m--;
        for(i = 0, j = 0; i < s1 && j < s2;){
                    cout<<nums1[i]<<" "<<nums2[j]<< " "<<ele<<'\n';
            if(nums1[i] <= nums2[j]){
                ele = nums1[i];
                i++;
            }
            else{
                ele = nums2[j];
                j++;
            }
            m--;
            if(m < 0){
                if(s%2 == 0){
                    cout<<i << ' '<<j<<'\n';
                    if(i < s1 && j < s2)
                        return (min(nums1[i], nums2[j]) + ele) / 2;
                    else if(i < s1)
                        return (ele + nums1[i]) / 2;
                    else if(j < s2)
                        return (ele + nums2[j]) / 2;
                    else
                        cout<<"error";
                }
                else
                    return ele;
            }
        }
        if(i == s1){
            if(s%2 == 0){
                return double(nums2[j + m + 1] + nums2[j + m ]) / 2;
            }
            else
                return nums2[j + m] ;
        }
        else{
        cout<<m<<' '<<i<<' '<<j<<' '<<s<<'\n';
            if(s%2 == 0){
                return double(nums1[i + m + 1] + nums1[i + m ]) / 2;
            }
            else
                return nums1[i + m];
        }
        return 0;
    }
};

int main() {
	Solution sol;
	vector<int> nums1 = {1, 2};
	vector<int> nums2 = {3, 4};
	cout<<sol.findMedianSortedArrays(nums1, nums2);
	return 0;
}