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
        // Flag true indicates relation "<" is expected, 
        // else ">" is expected.  The first expected relation 
        // is "<" 
        bool flag = true;
        for(int i = 0; i < n - 1; i++){
            if(flag){
                if(ve[i] > ve[i + 1]){
                    swap(ve[i], ve[i + 1]);
                }                
            }
            else{
                if(ve[i] < ve[i + 1]){
                    swap(ve[i], ve[i + 1]);
                }
            }
            flag = !flag;
        }

        for(int i = 0; i < n; i++){
            cout << ve[i] << ' ';
        } cout << endl;
    }
    return 0;
}