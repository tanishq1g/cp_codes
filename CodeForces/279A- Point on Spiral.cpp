#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    int c = 0;
    if((x == 0 && y == 0) || (x == 1 && y == 0)){
        cout << 0;
        return 0;
    }
    // cout << ((y > 0 && (x == y || y == -x))|| (y < 0 && (x == abs(y) + 1 || x == y)))<<endl;
    if(!((y > 0 && (x == y || y == -x))|| (y < 0 && (x == abs(y) + 1 || x == y)))){
        if(y > 0){
            if(abs(x) < y)
                x = -y;
            else{
                if(x >= 0)
                    y = x;
                else
                    y = x;
            }
        }
        else{
            if(abs(x) > y && abs(x) < abs(y) + 1){
                x = abs(y) + 1;
            }
            else{
                if(x >= 0)
                    y = x;
                else
                    y = x;
            }
        }
    }
    // cout << x << ' ' << y << endl;
    c += 4 * (abs(x) - 1);
    if(x < 0 && y < 0)
        c += 3;
    if(x < 0 && y > 0)
        c += 2;
    if(x > 0 && y > 0)
        c += 1;
    cout << c;
    return 0;
}