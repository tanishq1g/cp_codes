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
    vector<int> plusOne(vector<int>& digits) {
        int car = 0, temp;
        temp = digits[digits.size() - 1];
        digits[digits.size() - 1] = (temp + 1) % 10;
        car = (temp + 1) / 10;
        if(car == 0)
            return digits;

        for(int i = digits.size() - 2; i >= 0; i--){
            temp = digits[i];
            digits[i] = (temp + car) % 10;
            car = (temp + 1) / 10;
            // printvector(digits);cout<<car<<'\n';
            if(car == 0)
                break;
        }
        if(car != 0){
            vector<int>::iterator it = digits.begin();
            digits.insert(it, car);
        }
        return digits;
    }

    vector<int> plusOne_iterators(vector<int>& digits) {
        vector<int> res;
        int carry = 1;
        for(auto it=digits.rbegin(); it!=digits.rend(); it++) {
            int cur = *it;
            cur += carry;
            carry = cur/10;
            cur = cur%10;
            res.push_back(cur);
        }
        if(carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};

void main(){
    vector<int> digits = {9,9,9};
    Solution sol;
    digits = sol.plusOne(digits);
    for (size_t i = 0; i < digits.size(); i++)
    {
        cout<<digits[i]<<' ';
    }
    
}