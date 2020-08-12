#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <climits>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <utility>

using namespace std;
#define INF 1e7

// array 

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int s1 = nums1.size(), s2 = nums2.size();
//         int s = s1 + s2;
//         double ele;
//         int m = (s) / 2, i, j;
//         if(s%2 == 0) m--;
//         for(i = 0, j = 0; i < s1 && j < s2;){
//                     cout<<nums1[i]<<" "<<nums2[j]<< " "<<ele<<'\n';
//             if(nums1[i] <= nums2[j]){
//                 ele = nums1[i];
//                 i++;
//             }
//             else{
//                 ele = nums2[j];
//                 j++;
//             }
//             m--;
//             if(m < 0){
//                 if(s%2 == 0){
//                     cout<<i << ' '<<j<<'\n';
//                     if(i < s1 && j < s2)
//                         return (min(nums1[i], nums2[j]) + ele) / 2;
//                     else if(i < s1)
//                         return (ele + nums1[i]) / 2;
//                     else if(j < s2)
//                         return (ele + nums2[j]) / 2;
//                     else
//                         cout<<"error";
//                 }
//                 else
//                     return ele;
//             }
//         }
//         if(i == s1){
//             if(s%2 == 0){
//                 return double(nums2[j + m + 1] + nums2[j + m ]) / 2;
//             }
//             else
//                 return nums2[j + m] ;
//         }
//         else{
//         cout<<m<<' '<<i<<' '<<j<<' '<<s<<'\n';
//             if(s%2 == 0){
//                 return double(nums1[i + m + 1] + nums1[i + m ]) / 2;
//             }
//             else
//                 return nums1[i + m];
//         }
//         return 0;
//     }
// };

class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        priority_queue<int> le;
        priority_queue<int, vector<int>, greater<int> > ri;
        int s1 = v1.size();
        int s2 = v2.size();
        int x = s1 / 2;
        for(int i = 0; i < x; i++){
            le.push(v1[i]);
        }
        for(int i = x; i < s1; i++){
            ri.push(v1[i]);
        }
        int y;
        for(int i = 0; i < s2; i++){
            x = le.size();
            y = ri.size();
            cout << x << ' ' << y << '\n';
            if(x == 0 && y == 0){
                le.push(v2[i]);
            }
            else if(x == 0){
                if(ri.top() > v2[i]){
                    le.push(v2[i]);
                }
                else{
                    le.push(ri.top());
                    ri.pop();
                    ri.push(v2[i]);
                }
            }
            else if(y == 0){
                if(le.top() > v2[i]){
                    ri.push(le.top());
                    le.pop();
                    le.push(v2[i]);
                }
                else{
                    ri.push(v2[i]);
                }
            }
            else if(x == y){
                if(le.top() > v2[i]){
                    le.push(v2[i]);
                }
                else{
                    ri.push(v2[i]);
                }
            cout << le.top() << ' ' << ri.top() << '\n'; 
            }
            else if(x > y){
                if(le.top() > v2[i]){
                    ri.push(le.top());
                    le.pop();
                    le.push(v2[i]);
                }
                else{
                    ri.push(v2[i]);
                }
            // cout << le.top() << ' ' << ri.top() << '\n'; 
            }
            else if(x < y){
                if(le.top() > v2[i]){
                    le.push(v2[i]);
                }
                else{
                    le.push(ri.top());
                    ri.pop();
                    ri.push(v2[i]);
                }
            // cout << le.top() << ' ' << ri.top() << '\n'; 
            }
            cout << '\n';
        }
        x = le.size();
        y = ri.size();
        
        if(x == y){
            return double(le.top() + ri.top()) / 2;
        }
        else if(x > y){
            return le.top();
        }
        else{
            return ri.top();
        }
    }
};

int main() {
	Solution sol;
	vector<int> nums1 = {};
	vector<int> nums2 = {1,2,3, 4, 5};
	cout<<sol.findMedianSortedArrays(nums1, nums2);
	return 0;
}