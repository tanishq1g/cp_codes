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
    int n, t;
    cin >> n >> t;
    vector<int> ve(n);
    for(int i = 0; i < n; i++){
        cin >> ve[i];
    }
    int ma = 0, sum = 0, i, j;
    for(i = 0, j = 0; i < n && j < n; j++){
        sum += ve[j];
        if(sum > t){
            sum -= ve[i];
            ma = max(j - i, ma);
            i++;
        }
    }
    
    if(sum <= t)
        ma = max(j - i, ma);

    cout << ma;
    return 0;
}