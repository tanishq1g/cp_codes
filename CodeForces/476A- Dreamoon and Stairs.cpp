#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    if(n < m){
        cout << -1;
        return 0;
    }
    int max2 = n / 2, max1 = n % 2;
    int x = max2 + max1, y;
    if(x % m != 0)
        y = m - (x % m);
    else{
        cout << x;
        return 0;
    }
    // y = 2 * y;
    if(max2 < y){
        cout << -1 ; 
        return 0;
    }
    cout << max1 + max2 + y;
    return 0;
}