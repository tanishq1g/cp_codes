#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

// DYAMIC PROGRAMMING
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        //
        for(int i=1;i<=n;++i){
            if(static_cast<int>(sqrt(i))==sqrt(i))
                dp[i]=1;
        }
        //
        for(int i=1;i<=n;++i){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};