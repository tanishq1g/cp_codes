#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
#include <climits>
using namespace std;
// dynamic programming


int main(){
    int t, n, ma = INT_MIN;
    cin >> t;

    while(t--){
        cin >> n;
        vector<int> ve(n), dec(n), inc(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }
        ma = INT_MIN;
        for(int i = 0; i < n; i++){
            inc[i] = ve[i];
            for(int j = 0; j < i; j++){
                if(ve[j] < ve[i]){
                   inc[i] = max(inc[j] + ve[i], inc[i]);
               }
           }
        }
        // for(int i = 0; i < n; i++){
        //     cout << inc[i] << ' ';   
        // }cout << endl;
        
        for(int i = n - 1; i >= 0 ; i--){
            dec[i] = ve[i];
            for(int j = n - 1; j > i; j--){
                if(ve[j] < ve[i]){
                   dec[i] = max(dec[j] + ve[i], dec[i]);
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout << dec[i] << ' ';   
        // }cout << endl;
        for(int i = 0; i < n; i++){
            ma = max(inc[i] + dec[i] - ve[i], ma);
        }
        cout << ma << endl;
    }
    return 0;
}
