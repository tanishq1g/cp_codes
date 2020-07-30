#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    if(n == m){
        cout << 0 << ' ' << 0;
        return 0;
    }
    long long int x, y, kmin = 0, kmax = 0, num, dem, nx, ny;
    x = n / m;
    y = n % m;
    nx = m - y; //x
    ny = y; // x + y
    if(x < 2)
        kmin = 0;
    else{
        kmin += nx * x * (x - 1) / 2;
    }
    // cout << t << ' '<<kmin << ' ' << kmax<<endl;
    if(x + 1 < 2)
        kmin = 0;
    else
        kmin += ny * x * (x + 1) / 2;
    // cout << t << ' '<<kmin << ' ' << kmax<<endl;
    x = n - m + 1;
    if(x < 2)
        kmin = 0;
    else
        kmax = x * (x - 1) / 2;
    cout << kmin << ' ' << kmax<<endl;
    return 0;
}