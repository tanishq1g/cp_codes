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
        vector<int> ve(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }       
        int msum = INT_MIN, su = 0;
        for(int i = 0; i < n; i++){
            su += ve[i];
            msum = max(msum, su);
            if(su < 0){
                su = 0;
            }
        }
        cout << msum << '\n';
    }
    return 0;
}