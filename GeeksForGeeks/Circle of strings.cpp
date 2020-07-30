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
typedef INF 10000000;
// GRAPH

bool dfs(vector<vector<int> > &g, vector<int> &vis, vector<int> &exi, int ind, int &parent, int f){
    // cout << char(ind + 'a') << endl;
    vis[ind]++;
    bool ret = false;
    for(int i = 0; i < 26; i++){
        // cout << i << ' ' << g[ind][i] << endl;
        if(g[ind][i] == 1 && vis[i] < exi[i]){
            ret = ret || dfs(g, vis, exi, i, parent, 1);
        }
        else if(g[ind][i] == 1 && vis[i] == exi[i] && i == parent && f){
            // cout << ind <<' ' << i <<endl;
            return true;
        }
    }
    return ret;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> ve(n);
        // vector<vector<int> > fi(26, vector<int> ()), la(26, vector<int> ());
        vector<vector<int> > g(26, vector<int> (26, 0));
        vector<int> vis(26, 0);
        vector<int> exi(26, 0);
        for(int i = 0; i < n; i++){
            cin >> ve[i];
            // fi[ve[i].front() - 'a'].push_back(i);
            // la[ve[i].back() - 'a'].push_back(i);
            g[ve[i].front() - 'a'][ve[i].back() - 'a'] = 1;
            exi[ve[i].front() - 'a']++;
        }
        if(n == 0){
            cout << n << endl;
            continue;
        }
        if(n == 1){
            if(ve[0].front() == ve[0].back()){
                cout << 1 << endl;
            }
            else    
                cout << 0 << endl;
            continue;
        }
        int parent = ve[0].front() - 'a', f = 0;
        bool ret = dfs(g, vis, exi, parent, parent, 0);
        if(ret == false){
            cout << 0 << endl;
            continue;
        }
        bool flag = false;
        for(int i = 0; i < 26; i++){
            // cout << i << ' ' << exi[i] << ' ' << vis[i] << endl;
            if(exi[i] != vis[i]){
                flag = true;
                break;
            }
        }    
        if(flag)
            cout << 0 << endl;
        else
            cout << 1 << endl; 
    }
    return 0;
}