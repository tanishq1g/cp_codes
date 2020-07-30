#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    int ev = 0, od =  0;
    bool even = false;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x % 2 == 0){
            if(ev != 0){
                even = false;
            }
            ev = i + 1;
        }
        else{
            if(od != 0){
                even = true;
            }
            od = i + 1;
        }
    }
    if(even)
        cout << ev;
    else    
        cout << od;
    return 0;
}