#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    string s;
    cin >> s;
    int h = 10 * (s[0] - 48) + (s[1] - 48);
    int ph = 10 * (s[1] - 48) + (s[0] - 48);
    int m = 10 * (s[3] - 48) + (s[4] - 48);
    int pm = 10 * (s[4] - 48) + (s[3] - 48);
    if(ph > m && ph < 60){
        if(h < 10){
            cout << "0" + to_string(h) + ":";
        }
        else
            cout << to_string(h) + ":";
        if(ph < 10)
            cout << '0' << to_string(ph);
        else
            cout << to_string(ph);
    }
    else{
        if(h >= 15 && h < 20)
            h = 20;
        else if(h >= 5 && h < 10)
            h = 10;
        else
            h = (h + 1) % 24;
        string k = to_string(h);
        if(h < 10){
            k = '0' + k;
        }
        cout << k + ":" + k[1] + k[0];
    }
    return 0;
}