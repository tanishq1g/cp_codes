#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;
// dynamic programming


int main(){
    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        vector<int> ve(n), exc(n), inc(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }
        exc[0] = 0;
        inc[0] = ve[0];
        for(int i = 1; i < n; i++){
            exc[i] = inc[i - 1];
            inc[i] = min(inc[i - 1] + ve[i], exc[i - 1] + ve[i]);
        }
        cout<<min(inc[n - 1], exc[n - 1]) << endl;
    }
    return 0;
}
