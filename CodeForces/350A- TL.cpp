#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m;
    vector<int> vn(n), vm(m);
    for(int i = 0; i < n; i++){
        cin >> x;
        vn[i] = x;
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        vm[i] = x;
    }
    sort(vn.begin(), vn.end());
    sort(vm.begin(), vm.end());
    x = 2 * vn[0];
    if(x < vn[n - 1]){
        x = vn[n - 1];
    }
    if(x < vm[0]){
        cout << x;
    }
    else{
        cout << -1;
    }
    return 0;
}