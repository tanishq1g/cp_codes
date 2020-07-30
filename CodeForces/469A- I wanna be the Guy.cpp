#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x, y, te;
    vector<bool> vl(n, false);
    cin >> x;
    vector<int> vx(x);
    for(int i = 0; i < x; i++){
        cin >> te;
        vx[i] = te;
        vl[te - 1] = true;
    }
    cin >> y;
    vector<int> vy(y);
    for(int i = 0; i < y; i++){
        cin >> te;
        vy[i] = te;
        vl[te - 1] = true;
    }
    for(int i = 0; i < n; i++){
        if(vl[i] == false){
            cout << "Oh, my keyboard!";
            return 0;
        }   
    }
    cout << "I become the guy.";
    return 0;
}