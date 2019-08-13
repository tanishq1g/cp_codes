#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int divide(int dividend0, int divisor0) {
        long q = 0, ch, mul;
        long int dividend = dividend0;
        long int divisor = divisor0;
        int sign = dividend < 0 ^ divisor < 0 ? -1 : 1;
        if(sign == 1 && dividend != INT_MIN){
            dividend = abs(dividend);
            divisor = abs(divisor);
            for(int i = 31; i >= 0; i--){
                if(divisor > INT_MAX >> i) continue; 
                ch = divisor << i;
                cout<<"i "<<i <<' '<<ch<<'\n';
                if(dividend >= ch){
                    mul = 1<<i;
                    if(q > INT_MAX - mul){
                        return INT_MAX;
                    }
                    q += 1 << i;
                    dividend -= ch;
                }
            }
        }
        else{
            dividend = -1 * abs(dividend);
            divisor = -1 * abs(divisor);
            for(int i = 31; i >= 0; i--){
                // cout<<i<<' '<<divisor<<' '<<(INT_MIN >> i)<<'\n';
                if(divisor < INT_MIN >> i) {
                    continue;
                } 
                ch = -1*((-1*divisor) << i);
                // cout<<"i "<<i <<' '<<ch<<'\n';
                if(dividend <= ch){
                    // cout<<"in\n";
                    mul = 1<<i;
                    if(q > INT_MAX - mul + 1){
                        return INT_MIN;
                    }
                    q += 1 << i;
                    dividend -= ch;
                }
            }
        }
        
        if(dividend0 == INT_MIN){
            if(divisor0 < 0){
                if(q == INT_MIN)
                    return INT_MAX;
                return q;
            }
        }
        return sign * q;
    }
};
int main(){
    Solution sol;
    int a = -32;
    // cout<<(a>>2);
    cout<<sol.divide(INT_MIN, 1);
    return 0;
}