#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int n, m;

void func(vector<string> &ve, vector<vector<bool>> &ch, int r, int c, int f = 0){
    // cout << r << ' ' << c << ' ' << ((f == 0) ? 'B' : 'W') << endl;
    ve[r][c] = (f == 0) ? 'B' : 'W';
    ch[r][c] = false;
    if(r + 1 < n && ch[r + 1][c] && ve[r + 1][c] == '.'){
        func(ve, ch, r + 1, c, (f + 1) % 2);
    }
    if(r - 1 >= 0 && ch[r - 1][c] && ve[r - 1][c] == '.'){
        func(ve, ch, r - 1, c, (f + 1) % 2);
    }
    if(c + 1 < m && ch[r][c + 1] && ve[r][c + 1] == '.'){
        func(ve, ch, r, c + 1, (f + 1) % 2);
    }
    if(c - 1 >= 0 && ch[r][c - 1] && ve[r][c - 1] == '.'){
        func(ve, ch, r, c - 1, (f + 1) % 2);
    }
}

int main(){
    cin >> n >> m;
    vector<string> ve(n);
    vector<vector<bool>> ch(n, vector<bool>(m, true));
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        ve[i] = s;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ve[i][j] == '.'){
                func(ve, ch, i, j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << ve[i] << endl;
    }
    return 0;
}