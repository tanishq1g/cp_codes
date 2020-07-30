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

void permute(string a, int l, int r){
    string ret;
    // Base case  
    if (l == r)  
        cout << a << ' ';
    else{
        // Permutations made  
        for (int i = l; i <= r; i++){  
            // Swapping done 
            ret = "";
            if (l != 0){
                ret += a.substr(0, l);
            }
            ret += a[i];
            ret += a.substr(l, i - l);
            ret += a.substr(i + 1, r - i + 1);
            permute(ret, l+1, r);  
        }  
    }  
}  

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        permute(s, 0, s.size() - 1);    
        cout << endl;
    }
    return 0;
}