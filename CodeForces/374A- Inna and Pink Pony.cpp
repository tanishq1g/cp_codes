#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, a, b;
void func(int r, int c, vector<vector<int>> &ve, int t){
    if(r < 0 || r >= n || c < 0 || c >= m){
        // cout << t << "       avoid " << r << ' ' << c << endl;
        return;
    }
    // cout << t << "       " << r << ' ' << c << ' ' << ve[r][c] <<endl;
    if(ve[r][c] < t + 1){
        // cout << t << "       visited " << r << ' ' << c << endl;
        return;
    }
    ve[r][c] = t;
    if((r == 0 && c == 0) || (r == 0 && c == m - 1) || (r == n - 1 && c == 0) || (r == n - 1 && c == m - 1)){
        // cout << "       corfou " << r << ' ' << c << endl;
        return;
    }
    int m1,m2,m3,m4;
    func(r - a, c - b, ve, t + 1);
    func(r + a, c - b, ve, t + 1);
    func(r - a, c + b, ve, t + 1);
    func(r + a, c + b, ve, t + 1);
}

int func2(int x1, int y1, int x2, int y2){
    int d1 = abs(x2 - x1), d2 = abs(y2 - y1);
    if(d1 % a != 0 || d2 % b != 0)
        return INT_MAX;
    d1 /= a;
    d2 /= b;
    if((d1 + d2) % 2 != 0){
        return INT_MAX;
    }
    // cout << x1 << ' ' << x2 << ' ' << d1 << ' ' << d2<<endl; 
    return max(d1, d2);
}
int main(){
    int r, c;
    cin >> n >> m >> r >> c >> a >> b;
    if((r==1 || r==n) && (c==1 || c==m)){
        cout << "0\n";
        return 0;
    }
    if((r+a>n && r-a<1) || (c+b>m && c-b<1)){
        cout << "Poor Inna and pony!\n";
        return 0;
    }
    int asd = min(func2(1,1,r,c), min(func2(1, m,r,c), min(func2(n,1,r,c), func2(n,m,r,c))));
    if(asd == INT_MAX)
        cout << "Poor Inna and pony!\n";
    else
    cout << asd;
    // vector<vector<int>> ve(n, vector<int>(m, INT_MAX));
    // r--; c--;
    // ve[r][c] = 0;
    // // int m1,m2,m3,m4;
    // // int t= 0;
    // func(r - a, c - b, ve, 1);
    // func(r + a, c - b, ve, 1);
    // func(r - a, c + b, ve, 1);
    // func(r + a, c + b, ve, 1);
    // // cout << ve[0][0] << ' ' << ve[0][m - 1] << ' ' << ve[n - 1][0] << ' ' << ve[n - 1][m - 1];
    // int x = min(ve[0][0], min(ve[0][m - 1], min(ve[n - 1][0], ve[n - 1][m - 1])));
    // if(x == INT_MAX){
    //     cout << "Poor Inna and pony!";
    //     return 0;
    // }
    // cout << x;
    // return 0;
}