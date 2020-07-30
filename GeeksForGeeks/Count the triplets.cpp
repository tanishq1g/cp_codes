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
        sort(ve.begin(), ve.end());
        for(int i = 0; i < n; i++){
            cout << ve[i] << ' ';
        } cout << endl;
        int count = 0, su;
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0, k = i - 1; j < k;){
                su = ve[j] + ve[k];
                if(su == ve[i]){
                    count++;
                    // break;
                    j++; k--;
                }
                else if(su < ve[i]){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        if(count == 0)
            count = -1;
        cout << count << '\n';
    }
    return 0;
}