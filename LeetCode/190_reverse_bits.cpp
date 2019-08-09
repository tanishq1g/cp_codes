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
    uint32_t reverseBits(uint32_t n) {
        uint32_t re = 0;
        for (int i = 0; i < 32; i++){
            if(1 & n){
                cout<<i<<'\n';
                re |= (1<<(32 - i));
            }
            n = n>>1;
        }
    }
};
