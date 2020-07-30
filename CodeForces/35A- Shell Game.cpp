#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int x, a, b;
    cin >> x;
    
    for(int i = 0; i < 3; i++){
        cin >> a >> b;
        if(x == a){
            x = b;
        }
        else if(x == b){
            x = a;
        }
    }
    cout << x;
    return 0;
}