#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;

// OVERFLOW CONDITION INT MAX
class Solution {
public:
    int reverse(int x) {
        int flag = false;
        if(x < 0)
            flag = true;
        // x = abs(x);
        int y = 0;
        int temp;
        while(x != 0){
            temp = abs(x % 10);
            cout << y << ' ';
            if((y > INT_MAX / 10) || (y == INT_MAX / 10 && temp > 7) || (y < INT_MIN / 10) || (y == INT_MIN / 10 && temp < -8)){
                return 0;
            }
            y = y * 10 + temp;
            x /= 10;
            cout << x << ' ' << y << ' ' << temp << '\n';
        }
        if(flag)
            return -y;
        return y;
    }
};
int main() {
	Solution sol;
	int x;
    cin >> x;
    // cout << (x/10) << ' '<<(x%10);
	cout << sol.reverse(x);
	return 0;
}