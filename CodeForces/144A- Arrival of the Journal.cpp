#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, t;
    cin >> n;
    vector<int> v;
    int ma = INT_MIN, mi = INT_MAX;
    int ima = -1, imi = -1;
    for(int i = 0; i < n; i++){
        cin >> t;
        v.push_back(t);
        if(v[i] <= mi){
            mi = v[i];
            imi = i;
        }
        if(v[i] > ma){
            ma = v[i];
            ima = i;
        }
    }
    // cout<<mi<<' '<<imi<<' '<<ma<<' '<<ima<<'\n';
    int swaps = ima;
    if(ima > imi){
        swaps += n - imi - 2;
    }
    else{
        swaps += n - imi - 1;
    }
    cout<<swaps;
    return 0;
}