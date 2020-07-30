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

int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b, c;
        cin >> a >> b;
        int sa = a.size();
        c = a[sa - 1] + a.substr(0, sa - 1);
        // cout << c << '\n';
        if(c == b){
            cout << 1 << endl;
            continue;
        }
        c = a[sa - 2];
        c += a[sa - 1] + a.substr(0, sa - 2);
        // cout << c << '\n';
        if(c == b){
            cout << 1 << endl;
            continue;
        }
        c = a.substr(1, sa - 1) + a[0];
        // cout << c << '\n';
        if(c == b){
            cout << 1 << endl;
            continue;
        }
        c = a.substr(2, sa - 2) + a[0] + a[1];
        // cout << c << '\n';
        if(c == b){
            cout << 1 << endl;
            continue;
        }
        cout << 0 << endl;
    }
    return 0;
}