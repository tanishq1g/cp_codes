#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int main(){
    int k;
    cin >> k;
    string s;
    vector<string> ve(4);
    vector<int> p(10, 0);
    for(int i = 0; i < 4; i++){
        cin >> s;
        ve[i] = s;
        for(int j = 0; j < 4; j++){
            if(ve[i][j] == '.')
                continue;
            p[ve[i][j] - 48]++;
        }
    }
    k = 2 * k;
    for(int i = 1; i < 10; i++){
        if(p[i] > k){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}