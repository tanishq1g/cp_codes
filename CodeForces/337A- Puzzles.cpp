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
    vector<int> v(m);
    for(int i = 0; i < m; i++){
        cin >> x;
        v[i] = x;
    }
    sort(v.begin(), v.end());
    int mi = INT_MAX, te;
    for(int i = 0; i < m; i++){
        if(i + n - 1 < m){
            te = v[i + n - 1] - v[i];
            if(te < mi){
                mi = te;
            }
        }
    }
    cout<<mi;
    return 0;
}