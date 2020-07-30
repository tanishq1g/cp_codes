#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;

int main(){
    int x, a, b, c, y, d, e, f, z;
    cin >> x >> a >> b >> c >> y >> d >> e >> f >> z;
    int k = (a + b + c + d + e + f) / 2;
    x = k - a - b;
    y = k - c - d;
    z = k - e - f;
    cout << x << ' ' << a << ' ' << b << endl;
    cout << c << ' ' << y << ' ' << d << endl;
    cout << e << ' ' << f << ' ' << z;
    return 0;
}