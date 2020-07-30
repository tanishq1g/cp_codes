#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;


int main(){
    int x, y, z;
    cin >> x >> y >> z;
    float a, b, c;
    a = sqrt(x * y / z);
    b = sqrt(x * z / y);
    c = sqrt(y * z / x);
    cout << 4 * (a + b + c);
    return 0;
}