#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x, y;
    int l, r;
    cin >> l >> r;
    vector<bool> ve(101, true);
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        if(x > r || y < l)
            continue;
        for(int j = max(x, l); j < y; j++){
            ve[j] = false;
        }
    }
    int c = 0;
    for(int i = l; i < r; i++){
        if(ve[i]){
            // cout << i <<endl;
            c++;
        }
    }
    cout << c;
    return 0;
}