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
    for(int i = 1; i < n; i++){
        cin >> ve[i];   
    }
    int x = 1;
    while(x < t){
        x += ve[x];
        // cout<<x<<endl;
    }
    cout << (x == t ? "YES" : "NO");
    return 0;
}