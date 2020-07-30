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
        string s;
        cin >> s;
        int ss = s.size();
        bool flag = false;
        for(int i = ss - 1; i >= 0; i--){
            if(s[i] == '1'){
                flag = true;
                cout << i << '\n';
                break;
            }
        }
        if(!flag)
            cout << -1 << '\n';
    }
    return 0;
}