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
        string a, b;
        cin >> a >> b;
        int sa = a.size(), sb = b.size();
        vector<int> ve(26, 0);
        for(int i = 0; i < sa; i++){
            ve[a[i] - 'a']++;
        }
        for(int i = 0; i < sb; i++){
            ve[b[i] - 'a']--;
        }
        bool flag = false;
        for(int i = 0; i < 26; i++){
            if(ve[i] != 0){
                flag = true;
                break;
            }
        }
        if(flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}