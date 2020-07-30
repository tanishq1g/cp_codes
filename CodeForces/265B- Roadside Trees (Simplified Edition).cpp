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
    int n;
    cin >> n;
    int h, ch = 0, t = 0;
    cin >> h;
    t = h + 1;
    ch = h;
    for(int i = 1; i < n; i++){
        cin >> h;
        t += abs(ch - h) + 1 + 1;
        ch = h;
    }
    cout << t;
    return 0;
}