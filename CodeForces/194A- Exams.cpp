#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    if(3 * n <= k){
        cout << 0;
    }
    else{
        cout << 3 * n - k;
    }
    return 0;
}