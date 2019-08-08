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
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int maxp = 0, n = prices.size(), j;
        for (size_t i = 1; i < n; i++){
            // cout<<i<<' ';
            j = prices[i - 1];
            if(j < prices[i]){
                while(i < n && prices[i-1] < prices[i])
                    i++;
                i--;
                maxp += prices[i] - j;
            }
        }
        return maxp;
    }
};

int main(){
    vector<int> prices{7,1,5,3,6,4};
    Solution sol;
    cout<<sol.maxProfit(prices);
    while(1){
        char c;
        cout << "Enter a character: ";
        cin >> c;
        cout << "ASCII Value of " << c << " is " << int(c);
    }
    return 0;
}