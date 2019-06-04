#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int y = 0;
        int temp, xcopy = x;;
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
        return (xcopy == y);
    }
};

int main() {
	Solution sol;
	int x;
    cin >> x;
    // cout << (x/10) << ' '<<(x%10);
	cout << sol.isPalindrome(x);	
	return 0;
}