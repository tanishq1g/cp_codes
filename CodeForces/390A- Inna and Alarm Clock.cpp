#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;


int main(){
    int n, x, y;
    cin >> n;
    unordered_map<int, int> umapx, umapy;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if(umapx.find(x) == umapx.end())
            umapx[x] = 1;
        else
            umapx[x]++;
        if(umapy.find(y) == umapy.end())
            umapy[y] = 1;
        else
            umapy[y]++;
    }
    cout << min(umapx.size(), umapy.size());
    return 0;
}