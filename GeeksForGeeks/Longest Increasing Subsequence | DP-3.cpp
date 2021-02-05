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
    int t;
    cin >> t;
    while(t--){
        int n, ma;
        cin >> n;
        vector<int> ve(n), inc(n, 1);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }
        ma = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(ve[j] < ve[i]){
                    inc[i] = max(inc[i], inc[j] + 1);
                }
            }
            ma = max(ma, inc[i]);
        }
        cout << ma << endl;
    }
    return 0;
}

https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/