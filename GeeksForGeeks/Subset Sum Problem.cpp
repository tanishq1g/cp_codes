#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
#include <climits>
using namespace std;

// dynamic_programming
bool subsetgivensum(vector<vector<int> > &dp, vector<int> &ve, int n, int sum){
    if(sum < 0 || n < 0)
        return false;
    if(sum == 0)
        return true;
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    // cout << n << ' ' << sum << endl;
    dp[n][sum] = subsetgivensum(dp, ve, n - 1, sum) || subsetgivensum(dp, ve, n - 1, sum - ve[n]);
    return dp[n][sum];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, sum = 0;
        cin >> n;
        vector<int> ve(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];
            sum += ve[i];   
        }
        if(sum % 2 == 1){
            cout << "NO\n";
            continue;
        }
        vector<vector<int> > dp(n, vector<int> (sum + 1, -1));
        bool out = subsetgivensum(dp, ve, n - 1, sum / 2);
        if(out)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}