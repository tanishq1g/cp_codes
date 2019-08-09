#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int t, s = nums.size(), buf, loop = 1, indchflag = 0, indch = 0;
        if(s == 1 || k == 0)
            return;
        if(k>=s)
            k = k%s;
        t = k;
        if(t >= s) t = t - s;

        buf = nums[t];
        nums[t] = nums[0];

        for (int i = t; i < s;){
            cout<<"loop "<<loop<<" i "<<i<<" t "<<t<<" buf "<<buf<<"   aarray : ";
            for (int j = 0; j < s; j++)
            {
                cout<<nums[j]<<' ';
            }
            cout<<'\n';
            t = (i+k);
            if(t >= s) t = t - s;
            // nums[t] = buf;
            swap(nums[t], buf);
            cout<<"swap\n";
            i = t;

            loop++;
            if(loop == s)
                break;
            if(indchflag){
                t = indch + k;
                if(t >= s) t = t - s;
                buf = nums[t];
                nums[t] = nums[indch];
                i = t;
                indchflag = 0;
            }
            if(t == indch){
                indchflag = 1;
                indch++;
                cout<<"indch "<<indch<<' '<<indchflag<<'\n';
            }
        }

    }
};

int main(){
    vector<int> nums{1,2,3,4,5,6};
    int k = 6;
    Solution sol;
    sol.rotate(nums, k);
}