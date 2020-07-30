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
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7
// dynamic programming

int getmin(vector<vector<int> > &dp, string &s, int l, int r){
    // cout << l << ' ' << r << '\n';
    if(l > r)
        return INT_MAX;
    if(l == r)
        return 0;
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    if(l == r - 1){
        if(s[l] == s[r])
            return 0;
        else{
            return 1;
        }    
    }
    if(s[l] == s[r])
        dp[l][r] = getmin(dp, s, l + 1, r - 1);
    else{
        dp[l][r] = min(getmin(dp, s, l + 1, r), getmin(dp, s, l, r - 1)) + 1;
    }
    // cout << l << ' ' << r << ' ' << dp[l][r] << '\n';
    return dp[l][r];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ss = s.size();
        vector<vector<int> > dp(ss, vector<int> (ss, -1));
        cout << getmin(dp, s, 0, ss - 1) << endl;
    }
    return 0;
}