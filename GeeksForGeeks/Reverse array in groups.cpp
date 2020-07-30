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
        int n, k;
        cin >> n >> k;        
        vector<int> ve(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }
        for(int i = 0; i < n; i += k){
            if(i + k > n)
                reverse(ve.begin() + i, ve.end());
            else
                reverse(ve.begin() + i, ve.begin() + i + k);
        }
        for(int i = 0; i < n; i++){
            cout << ve[i] << ' ';
        } 
        cout << endl;
    }
    return 0;
}