#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, k, x;
    cin >> n >> k;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++){
        cin >> x;
        v[i] = x;
    }
    if(n < 3){
        cout << 0;
        return 0;
    }
    sort(v.begin(), v.end());
    int count = 0, in = 0;
    for(int i = n - 1; i >= in; i--){
        if(i - in + 1 < 3)
            break;
        if(5 - v[i] >= k){
            count++;
            in += 2;
        }
    }
    cout << count;
    return 0;
}