#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;


int main(){
    int n, m, k, x;
    cin >> n >> m >> k;
    vector<int> ve(n);
    for(int i = 0; i < n; i++){
        cin >> x;
        ve[i] = x;  
    }
    sort(ve.begin(), ve.end(), greater<int>());
    if(m <= k){
        cout << 0;
        return 0;
    }
    int s = k;
    for(int i = 0; i < n; i++){
        s += ve[i] - 1;
        // cout << s << endl;
        if(s >= m){
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}