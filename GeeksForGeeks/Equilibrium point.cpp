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
        vector<int> ve(n);
        int su1 = 0, su2 = 0; 
        for(int i = 0; i < n; i++){
            cin >> ve[i];
            su2 += ve[i];
        }
        if(n == 1){
            cout << 1 << '\n';
            continue;
        }
        if(n == 2){
            cout << -1 << '\n';
            continue;
        }
        su1 = ve[0];
        su2 = su2 - ve[0] - ve[1];
        bool flag = false;
        if(su1 == su2){
            cout << 2 << '\n';
            continue;
        }
        for(int i = 2; i < n; i++){
            su1 += ve[i - 1];
            su2 -= ve[i];
            if(su1 == su2){
                cout << i + 1 << '\n';
                flag = true;
                break;
            }
            
        }
        if(flag)
            continue;
        cout << -1 << '\n';
    }
    return 0;
}