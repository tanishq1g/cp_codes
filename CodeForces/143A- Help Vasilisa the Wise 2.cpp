#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int c1,c2,r1,r2,d1,d2,a,b,c,d;
    cin >> r1 >> r2;
    cin >> c1 >> c2;
    cin >> d1 >> d2;
    a = (c1 - d2 + r1) / 2;
    b = (d2 + r1 - c1) / 2;
    c = (d2 - r1 + c1) / 2;
    d = (r2 - c1 + d1) / 2;
    if(a == b || a == c || a == d || b == c || b == d || c == d || !(a > 0 && a < 10) || !(b > 0 && b < 10) || !(c > 0 && c < 10) || !(d > 0 && d < 10) || a + b != r1 || c + d != r2 || a + c != c1 || b + d != c2 || a + d != d1 || b + c != d2){
        cout << -1;
        return 0;
    }
    cout << a << ' ' << b << endl;
    cout << c << ' ' << d;
    return 0;
}
