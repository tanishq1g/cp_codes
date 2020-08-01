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

// RECURSION

int numberOfPaths(int m, int n) 
{ 
    // If either given row number is first or given column 
    // number is first 
    if (m == 1 || n == 1) 
        return 1; 
  
    // If diagonal movements are allowed then the last 
    // addition is required. 
    return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1); 
    // + numberOfPaths(m-1, n-1); 
} 

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int> > ve(n, vector<int> (m, 1));
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                ve[i][j] = ve[i - 1][j] + ve[i][j - 1];
            }
        }         
        cout << ve[n - 1][m - 1] << '\n';
    }
    return 0;
}