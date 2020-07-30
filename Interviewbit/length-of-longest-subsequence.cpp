#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
#include <climits>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> ve(n), vi(n), vd(n);
    for(int i = 0; i < n; i++){
        cin >> ve[i];   
    }
    if(n == 1)
        cout <<  1;
    
    
    vi[0] = 1;
    vd[n - 1] = 1;
    for(int i = 1; i < n; i++){
        vi[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(ve[i] > ve[j] && vi[i] < vi[j] + 1){
                vi[i] = vi[j] + 1;
            }
        }
        // cout << i << ' ' << vi[i]<<'\n';
    }
    for(int i = n - 2; i >= 0; i--){
        vd[i] = 1;
        for(int j = i + 1; j < n; j++){
            if(ve[i] > ve[j] && vd[i] < vd[j] + 1){
                vd[i] = vd[j] + 1;
            }
        }
        // cout << i << ' ' << vd[i]<<'\n';
    }
    int out = INT_MIN;
    for(int i = 0; i < n; i++){
        out = max(out, vi[i] + vd[i] - 1);
    }
    cout << out;
    return 0;
}

