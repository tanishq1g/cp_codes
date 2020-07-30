#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
using namespace std;

// dynamic_programming

int main(){
    int t0, n, count, slen;
    cin >> t0;
    string s;
    while(t0--){
        cin >> s;
        if(s == "")
            cout << 0 << endl;
        
        slen = s.size();
        vector<int> ve(slen, 0);
        ve[0] = 1;

        for(int i = 1; i < slen; i++){
            if(i % 2 == 1 && s.substr(0, i / 2 + 1) == s.substr(i / 2 + 1, i / 2 + 1)){
                ve[i] = min(ve[i - 1], ve[i / 2]) + 1;
            }
            else{
                ve[i] = ve[i - 1] + 1;
            }
            cout << i << ' ' << ' ' << ve[i] <<endl;
        }
        // cout << ve[slen - 1] << endl;
    }
    return 0;
}