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
        int n;        
        cin >> n;
        vector<int> va(n), vd(n);
        for(int i = 0; i < n; i++){
            cin >> va[i];
        }
        for(int i = 0; i < n; i++){
            cin >> vd[i];
        }
        
        sort(va.begin(), va.end());
        sort(vd.begin(), vd.end());
        int c = 0, mc = 0;
        for(int i = 0, j = 0; ; ){
            if(i == n){
                c -= (n - j);
                break;
            }
            if(j == n){
                c += n - i;
                mc = max(mc, c);
                break;
            }
            if(va[i] < vd[j]){
                c++;
                i++;
            }
            else{
                c--;
                j++;
            }
            mc = max(mc, c);
            // cout << i << ' ' << j << ' ' << c << ' ' << mc << '\n';
        }
        cout << mc << '\n';
    }
    return 0;
}

900, a
940, a  

2
a = 0900  0940 0950  1100 1500 1800
d = 0910 1200 1120 1130 1900 2000