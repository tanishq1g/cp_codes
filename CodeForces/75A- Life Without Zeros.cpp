#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int func(int x){
    int o = 0, r, e = 0;
    while(x > 0){
        r = x % 10;
        if(r != 0){
            o += r * pow(10, e);
            e++;
        }
        x /= 10;
    }
    return o;
}
int main(){
    int a, b, c, x = 0, y = 0, z;
    cin >> a >> b;
    c = a + b;
    x = func(a);
    y = func(b);
    z = func(c);
    // cout << c << ' '<<x<<' '<<y<<' '<<z<<endl;
    if(z == x + y)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}