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
        vector<int> al(257, 0);
        int ss = s.size();
        int in = 0;
        int ma = 0;
        for(int i = 0; i < ss; i++){
            // cout << in << ' ' << i << ' ' << ma << endl;
            if(al[s[i]] != 0){
                while(s[i] != s[in] && in <= i){
                    al[s[in]]--;
                    in++;
                }
                in++;
            }
            else{
                ma = max(ma, i - in + 1);
                al[s[i]]++;
            }
            // cout << s[i] << ' ' << al[s[i]] << endl;
        }
        cout << ma << endl; 
    }
    return 0;
}


