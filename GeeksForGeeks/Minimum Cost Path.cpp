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

// GRAPH

int n;

// int main(){
//     int t;
//     cin >> t;
//     int dx[] = {-1, 0, 1, 0}; 
//     int dy[] = {0, 1, 0, -1}; 
//     while(t--){
//         cin >> n;
//         vector<vector<int> > ve(n, vector<int> (n));
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 cin >> ve[i][j];
//             }
//         }
//         if(n == 1){
//             cout << ve[0][0] << endl;
//             continue;
//         }

//         vector<vector<bool> > vis(n, vector<bool> (n, false));
//         vector<vector<int> > out(n, vector<int> (n, INT_MAX));

//         int total = n * n, mdist, x, y, mix, miy;

//         list<pair<int, int> > lt;

//         vis[0][0] = true;
//         out[0][0] = ve[0][0];
//         out[1][0] = ve[0][0] + ve[1][0];
//         out[0][1] = ve[0][0] + ve[0][1];

//         lt.emplace_front(1, 0);
//         lt.emplace_front(0, 1);

//         list<pair<int, int> > :: iterator itr, mi;

//         while(vis[n - 1][n - 1] == false){
//             mdist = INT_MAX;

//             for(itr = lt.begin(); itr != lt.end(); itr++){
//                 // cout << itr->first << ' ' << itr->second << endl;
//                 if(mdist > out[itr->first][itr->second]){
//                     mdist = out[itr->first][itr->second];
//                     mix = itr->first;
//                     miy = itr->second;
//                     mi = itr;
//                 }
//             }
//             // cout << "min  " << mix << ' ' << miy << ' ' << out[mix][miy] << "   " << lt.size() << endl;
//             lt.erase(mi);
//             vis[mix][miy] = true;
//             for(int i = 0; i < 4; i++){
//                 x = mix + dx[i];
//                 y = miy + dy[i];
//                 if(x < 0 || y < 0 || x >= n || y >= n)
//                     continue;
//                 if(vis[x][y])
//                     continue;
//                 if(out[x][y] == INT_MAX){
//                     out[x][y] = min(out[x][y], out[mix][miy] + ve[x][y]);
//                     lt.emplace_back(x, y);
//                 }
//                 else{
//                     out[x][y] = min(out[x][y], out[mix][miy] + ve[x][y]);
//                 }
//                 // cout << "    " << x << ' ' << y << ' ' << out[x][y] << '\n';
//             }
//         }
//         cout << out[n - 1][n - 1] << endl;
        
//     }
//     return 0;
// }


int main(){
    int t;
    cin >> t;
    int dx[] = {-1, 0, 1, 0}; 
    int dy[] = {0, 1, 0, -1}; 
    while(t--){
        cin >> n;
        vector<vector<int> > ve(n, vector<int> (n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> ve[i][j];
            }
        }
        if(n == 1){
            cout << ve[0][0] << endl;
            continue;
        }

        vector<vector<bool> > vis(n, vector<bool> (n, false));
        vector<vector<int> > out(n, vector<int> (n, INT_MAX));

        int total = n * n, mdist, x, y, mix, miy;
        struct cmp{
            bool operator ()(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b){
                if(a.second < b.second)
                    return true;
                return false;
            }
        };

        multiset<pair<pair<int, int>, int>, cmp> lt;

        vis[0][0] = true;
        out[0][0] = ve[0][0];
        out[1][0] = ve[0][0] + ve[1][0];
        out[0][1] = ve[0][0] + ve[0][1];

        lt.insert(make_pair(make_pair(1, 0), out[1][0]));
        lt.insert(make_pair(make_pair(0, 1), out[0][1]));

        multiset<pair<pair<int, int>, int> > :: iterator itr, mi;

        while(vis[n - 1][n - 1] == false){
            mdist = INT_MAX;
            // for(itr = lt.begin(); itr != lt.end(); itr++){
            //     cout << itr->first.first << ' ' << itr->first.second << ' ' << itr->second << endl;
            // }
            itr = lt.begin();
            mix = itr->first.first;
            miy = itr->first.second;
            mi = itr;
            // cout << "min  " << mix << ' ' << miy << ' ' << out[mix][miy] << "   " << lt.size() << endl;
            lt.erase(mi);
            vis[mix][miy] = true;
            for(int i = 0; i < 4; i++){
                x = mix + dx[i];
                y = miy + dy[i];
                if(x < 0 || y < 0 || x >= n || y >= n)
                    continue;
                if(vis[x][y])
                    continue;
                if(out[x][y] == INT_MAX){
                    out[x][y] = min(out[x][y], out[mix][miy] + ve[x][y]);
                    lt.insert(make_pair(make_pair(x, y), out[x][y]));
                }
                else{
                    out[x][y] = min(out[x][y], out[mix][miy] + ve[x][y]);
                }
                // cout << "    " << x << ' ' << y << ' ' << out[x][y] << '\n';
            }
        }
        cout << out[n - 1][n - 1] << endl;
        
    }
    return 0;
}
