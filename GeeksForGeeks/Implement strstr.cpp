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


int strstr(string s, string x){
    int ss = s.size(), sx = x.size();
    for(int i = 0; i < ss; i++){
        // cout << i << '\n';
        int k = i, flag = 1;
        for(int j = 0; j < sx; j++, k++){
            // cout << k << ' ' << j << '\n';
            if(s[k] != x[j]){
                flag = 0;
                break;
            }
        }
        if(flag){
            return i;
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, x;
        cin >> s >> x;
        cout << strstr(s, x) << '\n';        
    }
    return 0;
}
