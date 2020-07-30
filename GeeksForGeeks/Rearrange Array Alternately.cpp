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
        int c = 0;
        for(int i = 0, j = n - 1; i <= j; ){
            if(c == 0){
                cout << ve[j] << ' ';
                j--;
            }
            else{
                cout << ve[i] << ' ';
                i++;
            }
            c = (c + 1) % 2;
        }
        cout << endl;
    }
    return 0;
}