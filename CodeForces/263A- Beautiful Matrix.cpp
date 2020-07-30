#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    vector<vector<int>> v(5, vector<int>(5, 0));
    int x;
    int r, c;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> x;
            v[i][j] = x;
            if(x == 1){
                r = i; c = j;
            }  
        }
    }
    cout << abs(2 - c) + abs(2 - r);
    return 0;
}