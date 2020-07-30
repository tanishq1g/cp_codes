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
// GRAPH

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n;
        vector<int> ve(31, -1);

        for(int i = 0; i < n; i++){
            cin >> x >> y;
            ve[x] = y;
        }

        vector<bool> vis(31, false);
        queue<pair<int, int> > q;
        pair<int, int> pa;
        q.push(make_pair(1, 0));
        vis[1] = true;
        int ret = -1;
        while(!q.empty()){
            pa = q.front();
            q.pop();
            for(int i = pa.first + 1; i <= pa.first + 6; i++){
                if(vis[i])
                    continue;
                if(ve[i] == -1){
                    q.push(make_pair(i, pa.second + 1));
                    vis[i] = true;
                    if(i == 30){
                        ret = pa.second + 1;
                        break;
                    }
                }
                else{
                    q.push(make_pair(ve[i], pa.second + 1));
                    vis[ve[i]] = true;
                    if(ve[i] == 30){
                        ret = pa.second + 1;
                        break;
                    }
                }
            }
            if(ret != -1)
                break;
        } 
        cout << ret << '\n';
    }
    return 0;
}