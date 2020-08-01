#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <climits>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// RECURSION

int n, m, o, k;
void func(vector<vector<int> > &ve, int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m)
        return;
    if(ve[x][y] != o)
        return;
    ve[x][y] = k;
    func(ve, x, y - 1);
    func(ve, x, y + 1);
    func(ve, x - 1, y);
    func(ve, x + 1, y);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int> > ve(n, vector<int> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> ve[i][j];
            }
        }         
        int x, y;
        cin >> x >> y >> k;
        o = ve[x][y];
        func(ve, x, y);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << ve[i][j] << ' ';        
            }
        }
        cout << '\n';
    }
    return 0;
}
