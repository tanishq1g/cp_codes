#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int l,r;
    int tot = 0, cur = 1;    
    for(int i = 0; i < n; i++){
        cin >> l>> r;
        if(l == cur){
            tot += r - l + 1;
            cur += r - l + 1;
        }
        else{
            cur += x * ((l - cur) / x);
            tot += r - cur + 1;
            cur += r - cur + 1;
        }
    }
    cout << tot;
    return 0;
}