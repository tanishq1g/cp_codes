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
    int n,m;
    cin >> n;
    vector<int> vn(n);
    for(int i = 0; i < n; i++){
        cin >> vn[i];
    }
    cin >> m;
    vector<int> vm(m);
    for(int i = 0; i < m; i++){
        cin >> vm[i];
    }
    sort(vn.begin(), vn.end());
    sort(vm.begin(), vm.end());
    int count = 0, x;
    for(int i = 0,j = 0; i < n && j < m;){
        x = vn[i] - vm[j];
        if(x == 1 || x == 0 || x == -1){
            i++;j++;count++;
        }
        else if(x > 1){
            j++;
        }
        else if(x < -1){
            i++;
        }
    }
    cout << count;
    return 0;
}