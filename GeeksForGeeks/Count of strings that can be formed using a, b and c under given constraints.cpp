#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;
// dynamic programming

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << 1 + n + n * (n - 1) / 2 + n + n * (n - 1) + n * (n - 1) * (n - 2) / 2 << endl;
    }
    return 0;
}



// C++ program to count number of strings
// of n characters with
#include<bits/stdc++.h>
using namespace std;

// n is total number of characters.
// bCount and cCount are counts of 'b'
// and 'c' respectively.
int countStr(int n, int bCount, int cCount)
{
    // Base cases
    if (bCount < 0 || cCount < 0) return 0;
    if (n == 0) return 1;
    if (bCount == 0 && cCount == 0) return 1;

    // Three cases, we choose, a or b or c
    // In all three cases n decreases by 1.
    int res = countStr(n-1, bCount, cCount);
    res += countStr(n-1, bCount-1, cCount);
    res += countStr(n-1, bCount, cCount-1);

    return res;
}

// Driver code
int main()
{
    int n = 3;  // Total number of characters
    cout << countStr(n, 1, 2);
    return 0;
}


// C++ program to count number of strings
// of n characters with
#include<bits/stdc++.h>
using namespace std;

// n is total number of characters.
// bCount and cCount are counts of 'b'
// and 'c' respectively.
int countStrUtil(int dp[][2][3], int n, int bCount=1,
                 int cCount=2)
{
    // Base cases
    if (bCount < 0 || cCount < 0) return 0;
    if (n == 0) return 1;
    if (bCount == 0 && cCount == 0) return 1;

    // if we had saw this combination previously
    if (dp[n][bCount][cCount] != -1)
        return dp[n][bCount][cCount];

    // Three cases, we choose, a or b or c
    // In all three cases n decreases by 1.
    int res = countStrUtil(dp, n-1, bCount, cCount);
    res += countStrUtil(dp, n-1, bCount-1, cCount);
    res += countStrUtil(dp, n-1, bCount, cCount-1);

    return (dp[n][bCount][cCount] = res);
}
