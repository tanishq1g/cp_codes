#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    long long int l, r;
    cin >> l >> r;
    if(r - l + 1 < 3){
        cout << -1;
        return 0;
    }
    if(l % 2 == 0){
        cout << l<< ' '<< l + 1<< ' '<< l + 2;
    }
    else{
        if(r - l + 1 == 3){
            cout << -1;
        }
        else{
            cout << l + 1<< ' '<< l + 2<< ' '<< l + 3;
        }
    }
    return 0;
}