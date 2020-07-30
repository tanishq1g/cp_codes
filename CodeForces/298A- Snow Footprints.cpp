#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = s.find("R");
    int l = s.find("L");
    // cout << r << ' ' << l;
    int cr = 0, cl = 0;
    for(int i = r; i >= 0 && i < n; i++){
        if(s[i] == 'R')
            cr++;
    }
    for(int i = l; i >= 0 && i < n; i++){
        if(s[i] == 'L')
            cl++;
    }
    // cout << cl << ' '<<cr<<'\n';
    if(cr == 0)
        cout << l + cl << ' ' << l;
    else if(cl == 0)
        cout << r + 1<< ' ' << r + cr + 1;
    else if(cr >= cl)
        cout << r + 1 << ' ' << r + cr;
    else
        cout << l + cl << ' ' << l + 1;
    return 0;
}