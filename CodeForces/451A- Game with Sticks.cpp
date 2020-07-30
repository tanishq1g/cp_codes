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
    int x = (n <= m) ? n : m;
    if(x % 2 == 0)
        cout << "Malvika";
    else
        cout << "Akshat"; 
    return 0;
}