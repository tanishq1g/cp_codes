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
// STRING

string palindrome(vector<vector<bool> > &dp, string &s, int l, int r){
    dp[l][r] = true;
    if(l >= r){
        return "";
    }
    for(int i = l, j = r; i <= j;){
        if(s[i] == s[j]){
            i++; j--;
        }
        else{
            string a = "", b = "";
            if(!dp[l + 1][r])
                a = palindrome(dp, s, l + 1, r);
            if(!dp[l][r - 1])
                b = palindrome(dp, s, l, r - 1);
            if(a.size() > b.size())
                return a;
            return b;
        }
    }
    return s.substr(l, r - l + 1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ss = s.size();
        vector<vector<bool> > dp(ss, vector<bool> (ss, false));
        string ret = palindrome(dp, s, 0, s.size() - 1);
        if(ret == ""){
            cout << s[0] << '\n';
        }
        else    
            cout << ret << '\n';
    }
    return 0;
}