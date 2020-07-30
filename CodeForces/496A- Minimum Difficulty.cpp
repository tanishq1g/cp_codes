#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> x;
        v[i] = x;
    }
    int d = INT_MAX, mi = -1;
    int dd = 0;
    for(int i = 1; i < n; i++){
        dd = max(dd, v[i] - v[i - 1]);
    }
    for(int i = 1; i < n - 1; i++){
        if(v[i + 1] - v[i - 1] < d){
            d = v[i + 1] - v[i - 1];
            mi = i;
        }
    }
    cout << max(d,dd);
    return 0;
}