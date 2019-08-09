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
    // int trailingZeroes(int n) {
    //     int count5 = 0;
    //     int j;
    //     for (int i = 5; i <= n; i++)
    //     {
    //         cout<<"iiiii  "<<i<<'\n';
    //         j = i;
    //         while(j%5 == 0 && j > 0){
    //             cout<<"jjjjjjjjjj  "<<j<<'\n';
    //             j = j/5;
    //             count5++;
    //         }
    //     }
    //     return count5;
    // }

    // int trailingZeroes(int n) {
    //     int count5 = 0;
    //     int j = 1, ch;
    //     while(1){
    //         ch = pow(5,j);
    //         if(ch <= n){
    //             count5 += n/ch;
    //             j++;
    //         }
    //         else break;
    //     }
    //     return count5;
    // }

    int trailingZeroes(int n) {
        int r = 0;
        while(n >= 5){
            n /= 5;
            r += n;
        }
        return r;
    }
};

int main(){
    Solution sol;
    cout<<sol.trailingZeroes(100);
    return 0;
}