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
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// array

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int> > ve(n, vector<int> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> ve[i][j];
            }
        }         

        int l = 0, r = m - 1, u = 0, d = n - 1;

        while(l <= r  && u <= d){
            // cout << l << ' ' << r << ' ' << u << ' ' << d << '\n';

            for(int i = l; i <= r; i++){
                cout << ve[u][i] << ' ';
            }
            for(int i = u + 1; i <= d; i++){
                cout << ve[i][r] << ' ';
            }
            if(u != d){
                for(int i = r - 1; i >= l; i--){
                    cout << ve[d][i] << ' ';
                }
            }
            if(l != r){
                for(int i = d - 1; i > u; i--){
                    cout << ve[i][l] << ' ';
                }
            }
            l++;r--;u++;d--;
        }
        cout << endl;
    }
    return 0;
}
