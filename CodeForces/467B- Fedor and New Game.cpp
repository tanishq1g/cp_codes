#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
using namespace std;

int func(int n){
    int count = 0;
    while(n){
        count += n & 1;
        n >>= 1;
    }
    return count;
}
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ve(m);
    for(int i = 0; i < m; i++){
        cin >> ve[i];    
    }
    int f;
    cin >> f;
    int count = 0;
    for(int i = 0; i < m; i++){
        if(func(f ^ ve[i]) <= k)
            count++;
    }
    cout << count;
    return 0;
}