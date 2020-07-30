#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int r, c;
    cin >> r >> c;
    string ch;
    vector<string> v(r);
    vector<bool> vr(r, true), vc(c, true);
    for(int i = 0; i < r; i++){
        cin >> ch;
        v[i] = ch;
        for(int j = 0; j < c; j++){
            if(v[i][j] == 'S'){
                // cout<<i << ' '<< j<< '\n';
                vr[i] = false;
                vc[j] = false;
            }
        }
    }
    int count = 0, cr = 0;
    for(int i = 0; i < r; i++){
        if(vr[i]){
            // cout << i << '\n';
            count += c;
            cr++;
        }
    }
    for(int i = 0; i < c; i++){
        if(vc[i]){
            // cout << i << '\n';
            count += r - cr;
        }
    }
    cout << count;
    return 0;
}