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
        int maxp = INT_MIN;
        int l = prices[0], diff;
        for (size_t i = 1; i < prices.size(); i++){
            diff = prices[i] - l;
            if(diff < 0){
                l = prices[i];
            }
            maxp = max(maxp, diff)
        }
        if(maxp < 0)
            return 0;
        return maxp;
    }
};

int main(){
    vector<int> prices{7,1,}
    Solution sol;
    sol.generate(15);
    return 0;
}