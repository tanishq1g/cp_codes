#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int main(){
    int n;
    cin >> n;
    int r;
    do{
        r = n % 10;
        if(r >= 5){
            cout << "-O|";
            r = r - 5;
            for(int j = 0; j < r; j++){
                cout << "O";
            }
            r = 4 - r;
            cout << "-";
            for(int j = 0; j < r; j++){
                cout << "O";
            }
        }
        else{
            cout << "O-|";
            for(int j = 0; j < r; j++){
                cout << "O";
            }
            r = 4 - r;
            cout << "-";
            for(int j = 0; j < r; j++){
                cout << "O";
            }
        }
        cout << endl;
        n /= 10;
    }while(n > 0);
    return 0;
}