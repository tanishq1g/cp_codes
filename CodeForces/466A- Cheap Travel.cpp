#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;


int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(a * m <= b){
        cout << n * a;
    }
    else{
        cout << (b * (n / m)) + min(a * (n % m), b);
    }
    return 0;
}