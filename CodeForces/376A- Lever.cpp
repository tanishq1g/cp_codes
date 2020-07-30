#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int main(){
    string s;
    cin >> s;
    int p = s.find('^');
    long long int l = 0, r = 0;
    for(int i = p - 1; i >= 0; i--){
        if(s[i] > 48 && s[i] <= 57){
            l += (s[i] - 48) * (p - i);
        }
    }
    int ss = s.size();
    for(int i = p + 1; i < ss; i++){
        if(s[i] > 48 && s[i] <= 57){
            r += (s[i] - 48) * (i - p);
        }
    }
    if(l > r)
        cout << "left";
    else if(l < r)
        cout << "right";
    else    
        cout << "balance";
    return 0;
}