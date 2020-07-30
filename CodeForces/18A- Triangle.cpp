#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

bool func(int x1, int y1, int x2, int y2, int x3, int y3){
    if((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x3 == x2 && y3 == y2))
        return false;
    int a, b, c;
    b = (pow(x1 - x3, 2) + pow(y1 - y3, 2));
    a = (pow(x1 - x2, 2) + pow(y1 - y2, 2));
    c = (pow(x3 - x2, 2) + pow(y3 - y2, 2));
    // cout << a << ' ' << b << ' ' << c << endl;
    // cout << x1<<' '<< y1<<' '<< x2<<' '<< y2<<' '<< x3<<' '<< y3<<endl;
    int d = max(a, max(b, c));
    return ((d == a && d == b + c) || (d == b && d == a + c) || (d == c && d == a + b));
}
int main(){
    int x1, y1, x2, y2, x3, y3, a, b, c;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(func(x1, y1, x2, y2, x3, y3)){
        cout << "RIGHT";
        return 0;
    }
    if(func(x1 - 1, y1, x2, y2, x3, y3)){
        cout << "ALMOST";
        return 0;
    }
    if(func(x1 + 1, y1, x2, y2, x3, y3)){
        cout << "ALMOST";
        return 0;
    }
    if(func(x1, y1 - 1, x2, y2, x3, y3)){
        cout << "ALMOST";
        return 0;
    }
    if(func(x1, y1 + 1, x2, y2, x3, y3)){
        cout << "ALMOST";
        return 0;
    }
    if(func(x1, y1, x2 - 1, y2, x3, y3)){
        cout << "ALMOST";
        return 0;
    }
    if(func(x1, y1, x2 + 1, y2, x3, y3)){
        cout << "ALMOST";
        return 0;
    }
    if(func(x1, y1, x2, y2 - 1, x3, y3)){
        cout << "ALMOST";
        return 0;
    }
    if(func(x1, y1, x2, y2 + 1, x3, y3)){
        cout << "ALMOST";
        return 0;
    }
    if(func(x1, y1, x2, y2, x3 - 1, y3)){
        cout << "ALMOST";
        return 0;
    }
    if(func(x1, y1, x2, y2, x3 + 1, y3)){
        cout << "ALMOST";
        return 0;
    }
    if(func(x1, y1, x2, y2, x3, y3 - 1)){
        cout << "ALMOST";
        return 0;
    }
    if(func(x1, y1, x2, y2, x3, y3 + 1)){
        cout << "ALMOST";
        return 0;
    }
    cout << "NEITHER";
    return 0;
}