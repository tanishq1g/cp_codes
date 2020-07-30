#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;


int main(){ 
    int n, d;
    cin >> n >> d;
    vector<int> v (n);
    int x;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        v[i] = x;
        sum +=  x;
    }
    int y = d - sum - 10 * (n - 1);
    // cout<<sum<<' '<<endl;
    if(10 * (n - 1) + sum > d){
        cout << -1;
    }
    else
        cout << 2 * (n - 1) + y / 5;
    return 0;
}