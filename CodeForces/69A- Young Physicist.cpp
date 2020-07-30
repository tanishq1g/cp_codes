#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, x, y, z;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3,0));
    for(int i = 0; i < n; i++){
        cin >> x >> y >> z;
        v[i][0] = x; v[i][1] = y; v[i][2] = z; 
    }
    for(int i = 0; i < 3; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += v[j][i];
        }
        if(sum != 0){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}