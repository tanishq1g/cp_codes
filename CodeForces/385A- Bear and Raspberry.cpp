#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, c;
    cin >> n >> c;
    vector<int> ve(n);
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        ve[i] = x;
    }
    int ma = 0, ch;
    for(int i = 0; i < n - 1; i++){
        ch = ve[i] - ve[i + 1] - c;
        if(ch > ma){
            ma = ch;
        }
    }
    cout << ma;
    return 0;
}