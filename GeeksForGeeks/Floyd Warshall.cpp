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

struct cmp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.second <= b.second)
            return true;
        return false;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;        
        cin >> n;
        vector<vector<int> > ve(n, vector<int> (n));
        string s;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> s;
                if(s == "INF")
                    ve[i][j] = INF;
                else
                    ve[i][j] = stoi(s);
                cout<< ve[i][j] << ' ';
            }    
            cout << endl;
        }
        
        vector<vector<int> > out(n, vector<int> (n, INF));
        for(int src = 0; src < n; src++){
            cout << "Src " << src << endl;
            vector<bool> vis(n, false);

            out[src][src] = 0;
            vis[src] = true;
            
            set<pair<int, int>> st;
            set<pair<int, int> > :: iterator itr, miitr;

            for(int i = 0; i < n; i++){
                if(ve[src][i] != INF && src != i){
                    out[src][i] = ve[src][i];
                    st.insert(make_pair(i, out[src][i]));
                }
            }
            int mdist, mi;
            while(!st.empty()){
                cout << "size " << st.size() <<'\n';
                for(itr = st.begin(); itr != st.end(); itr++){
                    cout << itr->first << ' ' << itr->second << endl;
                }

                miitr = st.begin();
                mi = miitr->first;
                cout << "mi "<<mi << '\n';
                st.erase(miitr);
                vis[mi] = true;
                for(int i = 0; i < n; i++){
                    if(ve[mi][i] != INF){
                        cout << "i " << i << ' ' << out[src][i] << '\n';
                        if(out[src][i] == INF){
                            out[src][i] = min(out[src][i], out[src][mi] + ve[mi][i]);
                            st.insert(make_pair(i, out[src][i]));
                        }
                        else{
                            pair<int, int> p = make_pair(i, out[src][i]);
                            cout << p.first << ' ' << p.second << '\n';
                            itr = st.find(p);
                            cout << itr ->first << ' ' << itr->second << '\n';
                            st.erase(itr);
                            out[src][i] = min(out[src][i], out[src][mi] + ve[mi][i]);
                            st.insert(make_pair(i, out[src][i]));
                        }

                    }
                }
                cout << '\n' << '\n';
            }
        cout << "over\n";
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(out[i][j] == INF)
                    cout << "INF ";   
                else    
                    cout << out[i][j] << ' ';
            }   
            cout << '\n';
        }
    }
    return 0;
}