#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    long long int p, k, x;
    cin >> p;
    int ctr = 0;
    k = p - 1;
    bool no;
    for(int i = 1; i < p; i++){
        no = false;
        x = 1;
        for(int j = 1; j < k; j++){
            x *= i;
            x %= p;
                // cout << i << ' ' << j << ' ' << x << endl;
            if(x == 1){
                no = true;
                break;
            }
        }
        if(no)
            continue;
        x *= i;
        if(x % p == 1){
            ctr++;
        // cout << i <<' '<<ctr<< endl;
        }
    }
    cout << ctr;
    return 0;
}