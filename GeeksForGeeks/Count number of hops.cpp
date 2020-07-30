#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
using namespace std;

// dynamic_programming

int main(){
    int t, n;
    cin >> t;
    vector<int> ve(101, 0);
    ve[0] = 1;
    ve[1] = 1;
    ve[2] = 2;
    ve[3] = 4;
    for(int i = 4; i < 101; i++){
        ve[i] = ve[i-1] + ve[i-2] + ve[i-3]; 
    }
    while(t--){
        cin >> n;
        cout << ve[n] << endl;
    }
    return 0;
}