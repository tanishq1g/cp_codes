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

// array

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n;
        vector<int> ve(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }      
        cin >> m;  
        sort(ve.begin(), ve.end());
        int mi = INT_MAX;
        for(int i = 0; i + m - 1< n; i++){
            mi = min(mi, ve[i + m - 1] - ve[i]);
        }
        cout << mi << '\n';
    }
    return 0;
}