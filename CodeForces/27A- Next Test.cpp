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
    if(n == 0){
        cout << 1;
        return 0;
    }
    vector<int> ve(n);
    for(int i = 0; i < n; i++){
        cin >> x;
        ve[i] = x;
    }
    sort(ve.begin(), ve.end());
    if(ve[0] != 1){
        cout << 1;
        return 0;
    }
    for(int i = 1; i < n; i++){
        if(ve[i] - ve[i - 1] != 1){
            cout << ve[i - 1] + 1;
            return 0;
        }
    }
    cout << ve[n - 1] + 1;
    return 0;
}