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
        int n;
        cin >> n;
        vector<int> ve(n), l(n), r(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }
        if(n == 1 || n == 2){
            cout << 0 << '\n';
            continue;
        }
        l[0] = INT_MIN;
        r[n - 1] = INT_MIN;
        for(int i = 1; i < n; i++){
            l[i] = max(ve[i - 1], l[i - 1]);
        }
        for(int i = n - 2; i > 0; i--){
            r[i] = max(ve[i + 1], r[i + 1]);
        }
        int vol = 0;
        n--;
        for(int i = 1; i < n; i++){
            vol += max(0, min(l[i], r[i]) - ve[i]);
        }
        cout << vol << '\n';
    }
    return 0;
}