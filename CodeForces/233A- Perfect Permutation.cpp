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
    if(n % 2 == 0){
        int dd = 2;
        for(int i = 0; i < n; i += 2){
            cout << dd<< ' '<< dd - 1<< ' ';
            dd += 2;
        }
    }
    else
        cout << -1;
    return 0;
}