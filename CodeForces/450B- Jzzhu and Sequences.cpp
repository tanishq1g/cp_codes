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
    long long int x, y, z;
    cin >> x >> y;
    int n;
    cin >> n;
    n = n % 6;
    if(n == 0)
        n = 6;
    if(n == 1){
        x = (x % 1000000007);
        if(x < 0)
            x += 1000000007;
        cout << (x % 1000000007);
    }
    else if(n == 2){
        y = (y % 1000000007);
        if(y < 0)
            y += 1000000007;
        cout << (y % 1000000007);
    }
    else{
        for(int i = 3; i <= n; i++){
            z = (y - x) % 1000000007;
            if(z < 0)
                z += 1000000007;
            x = y;
            y = z;
        }
        cout << y;
    }
    return 0;  
}