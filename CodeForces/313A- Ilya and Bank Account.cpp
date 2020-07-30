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
    if(n >= 0)
        cout << n;
    else{
        int nn = n;
        n *= -1;
        int r0, r10;
        r0 = n % 10;
        n /= 10;
        if(n == 0){
            cout << 0;
            return 0;
        }
        r10 = n % 10;
        n /= 10;
        cout << -1 * (10 * n + (((r0 > r10) ? r10 : r0)));
    }
    return 0;
}