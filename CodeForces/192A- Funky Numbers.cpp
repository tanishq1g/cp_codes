#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    long long int n, x;
    cin >> n;
    int l = sqrt(2 * n);
    for(int i = 1, j = l; i <= j;){
        x = i * (i + 1) / 2 + j * (j + 1) / 2;
        // cout << i << ' ' << j << ' ' << x<<endl;
        if(x == n){
            cout << "YES";
            return 0;
        }
        else if(x < n){
            i++;
        }
        else{
            j--;
        }
    }
    cout << "NO";
    return 0;
}