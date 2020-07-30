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
    int m, n, x, n0 = 0;
    cin >> m >> n;
    vector<bool> r(m, true), c(n, true);
    vector<int> ox, oy;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> x;
            if(x == 0){
                n0++;
                r[i] = false;
                c[j] = false;
            }
            else{
                ox.push_back(i);
                oy.push_back(j);
            }
        }
    }
    if(n0 == n * m){
        cout << "YES\n";
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << 0 <<' ';
            }
            cout << endl;
        }
        return 0;
    }

    vector<vector<int>> out(m, vector<int> (n, 1));
    if(n0 != 0){
        int lo = ox.size();
        for(int i = 0; i < lo; i++){
            if((r[ox[i]] || c[oy[i]]) == false){
                cout << "NO";
                return 0;
            }
        }
        int cr = 0, cc = 0;
        for(int i = 0; i < m; i++){
            if(r[i] == false){
                cr++;
                for(int j = 0; j < n; j++){
                    out[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(c[i] == false){
                cc++;
                for(int j = 0; j < m; j++){
                    out[j][i] = 0;
                }
            }
        }
        if(cr == m || cc == n){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << out[i][j] <<' ';
        }
        cout << endl;
    }
    return 0;
}