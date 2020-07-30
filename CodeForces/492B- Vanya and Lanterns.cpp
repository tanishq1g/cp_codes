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
    long double n, l;
    cin >> n >> l;
    vector<long double> ve(n);
    for(int i = 0; i < n; i++){
        cin >> ve[i];   
    }
    sort(ve.begin(), ve.end());
    long double d = ve[0] - 0, x;
    for(int i = 1; i < n; i++){
        // x = (ve[i] - ve[i - 1]) / 2;
        // cout << ve[i] << '\n';
        d = fmax(d, (ve[i] - ve[i - 1]) / 2);
    }
    d = fmax(d, l - ve[n - 1]);
    cout << fixed << setprecision(10) << d;
    return 0;
}