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
    vector<string> ve(n);
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        ve[i] = s;
    }
    char ch1 = ve[0][0], ch2 = ve[0][1];
    if(ch1 == ch2){
        cout << "NO";
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(ve[i][i] != ch1){
            cout << "NO";
            return 0;
        }
        if(ve[i][n - i - 1] != ch1){
            cout << "NO";
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j || i + j == n - 1)
                continue;
            if(ve[i][j] != ch2){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}