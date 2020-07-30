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
        string ret = "";
        while (1){
            ret = "";
            int ss = s.size();

            for(int i = 0; i < ss - 1; i++){
                if(s[i] != s[i + 1]){
                    ret += s[i];
                    continue;
                }
                while(s[i] == s[i + 1]){
                    i++;
                }    
            }
            if(ss >= 2 && s[ss - 2] != s[ss - 1])
                ret += s[ss - 1];
            if(ss == 1)
                ret = s;
            if(s == ret)
                break;
            cout << s << ' ' << ret << '\n';
            s = ret;
        }
        cout << ret << '\n';
    }
    return 0;
}