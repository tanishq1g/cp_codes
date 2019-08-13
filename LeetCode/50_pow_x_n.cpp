#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    double myPow(double x, int n0) {
        double re = 1;
        bool div = false;
        long n = n0;
        if(n == 0) return x;
        if(n < 0){
            div = true;
            n = -n;
        }
        for (int i = 0; i < 32; i++){
            if(n & 1<<i){
                re *= x;
            }
            x = x*x;
        }
        if(div) return 1/re;
        return re;
    }
};