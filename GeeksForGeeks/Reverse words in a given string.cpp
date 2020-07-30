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
        string s;
        cin >> s;
        int ss = s.size();
        string ret = "";
        int lo = -1;
        for(int i = ss - 1; i >= 0; i--){
            if(s[i] == '.'){
                if(i + 1 < ss){
                    ret += s.substr(i + 1, lo - i - 1);
                    ret += '.';
                    lo = i;
                }
            }
        }
        if(lo != ss){
            ret += s.substr(0, lo - 0);
        }
        cout << ret << '\n';
    }
    return 0;
}