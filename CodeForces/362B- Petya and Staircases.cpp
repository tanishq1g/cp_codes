#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> ve(m);
    for(int i = 0; i < m; i++){
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    int cur = 1;
    for(int i = 0; i < m;){
        // cout << i<<' ' << cur << '\n';
        if(ve[i] == cur){
            cout << "NO";
            return 0;
        }
        cur = ve[i] - 1;
        if(i + 1 < m){
            if(ve[i + 1] - ve[i] == 1){
                // if(i + 2 < m){
                //     if(ve[i + 2] - ve[i] == 2){
                //         cur = ve[i + 2] + 1;
                //         i += 3;
                //     }
                //     else{
                //         cur = ve[i + 1] + 1;
                //         i += 2;
                //     }
                // }
                // else{
                    cur = ve[i + 1] + 1;
                    i += 2;
                // }
            }
            else{
                cur = ve[i] + 1;
                i += 1;
            }
        }
        else{
            cur = ve[i] + 1;
            i += 1;
        }
    }
    if(cur <= n){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}