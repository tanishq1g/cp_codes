#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int gcd(int a, int b){
    if(a == 0)
        return b;
    return gcd(b % a, a);
}

int main(){
    int n, x;
    cin >> n;
    vector<int> ve(n);
    for(int i = 0; i < n; i++){
        cin >> x;
        ve[i] = x;
    }
    int g = ve[0];
    for(int i = 1; i < n; i++){
        g = gcd(ve[i], g);
    }   
    cout << g * n;
    return 0;
}