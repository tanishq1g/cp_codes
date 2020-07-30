#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> vr, vl;
    int l = s.size();
    for(int i = 0; i < l; i++){
        if(s[i] == 'R')
            vr.push_back(i + 1);
        else
            vl.push_back(i + 1);
    }
    
    int lr = vr.size(), ll = vl.size();
    for(int i = 0; i < lr && i < ll; i++){
        cout << vl[i] << ' ' << vr[i] << endl;
    }
    if(ll > lr){
        for(int i = lr; i < ll; i++){
            cout << vl[i] << ' ' << vl[i + 1] << endl;
            i++;
        }
    }
    else{
        for(int i = ll; i < lr; i++){
            cout << vr[i] << ' ' << vr[i + 1] << endl;
            i++;
        }
    }
    return 0;
}