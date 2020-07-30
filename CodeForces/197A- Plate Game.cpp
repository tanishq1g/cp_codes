#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int a, b, r;
    cin >> a >> b >> r;
    r *= 2;
    if(r <= a && r <= b)
        cout << "First";
    else
        cout << "Second";
    return 0;
}