#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <climits>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// dynamic programming, trees

class Solution {
public:
    //for every start and end index, calculate and store it in dp.
    //for every start and end indexes, first put one element to the left and rest all in the right. Next, put 2 elements to left and rest all to the right and so on.
    vector<vector<pair<int, int>>> dp;
    pair<int, int> calculate(vector<int>& arr, int st, int end) {
        if(st == end) {
            return {arr[st], 0};
        }
        else if(dp[st][end].second != -1) {
            return dp[st][end];
        }
        int minprod = INT_MAX, maxleaf = INT_MIN;
        for(int i=st; i<end; i++) {
            pair<int,int> left = calculate(arr, st, i);
            pair<int,int> right = calculate(arr, i+1, end);
            minprod = min(minprod, left.second+right.second+(left.first * right.first));
            maxleaf = max(left.first,right.first);
        }
        dp[st][end] = {maxleaf, minprod};
        return dp[st][end];
    }
    int mctFromLeafValues(vector<int>& arr) {
        dp = vector<vector<pair<int, int>>>(arr.size(), vector<pair<int, int>>(arr.size(), {INT_MIN,-1}));
        return calculate(arr,0, arr.size()-1).second;
    }
};

int main(){
    Solution sol;
    vector<int> arr{6,2,4};
    cout << sol.mctFromLeafValues(arr);
    return 0;
}
