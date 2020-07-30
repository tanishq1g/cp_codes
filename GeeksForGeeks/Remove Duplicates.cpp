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
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        string out = "";
        vector<bool> ve(257, false);
        int ss = s.size();
        for(int i = 0; i < ss; i++){
            if(ve[s[i]] == false){
                ve[s[i]] = true;
                out += s[i];
            }
        }
        cout << out << endl;
    }
    return 0;
}