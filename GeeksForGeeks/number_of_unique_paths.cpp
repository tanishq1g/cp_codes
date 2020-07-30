#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;
// dynamic programming
int main(){
    int t, m, n;
    cin >> t;
    while(t--){
        cin >> m >> n;
        vector<vector<int>> ve(m, vector<int> (n, 1));
        for(int i = 1; i < m; i++){
            ve[i][0] = 1;
        }
        for(int i = 1; i < n; i++){
            ve[0][i] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                ve[i][j] = ve[i][j - 1] + ve[i - 1][j];
            }
        }
        cout << ve[m-1][n-1] << endl;
    }
    return 0;
}