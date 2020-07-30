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

// STACK AND HEAPS

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<char> ve(n);
        list<char> li;
        list<char>::iterator itr;
        vector<pair<int, list<char>::iterator > > m(26, make_pair(0, itr));
        int x;
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
            x = ve[i] - 'a';
            if(m[x].first == 0){
                m[x].first = 1;
                li.push_back(ve[i]);
                itr = li.end();
                advance(itr, -1);
                m[x].second = itr;
            }
            else if(m[x].first == 1){
                m[x].first = 2;
                li.erase(m[x].second);
            }
            if(li.empty())
                cout << -1 << ' ';
            else
                cout << *li.begin() << ' ';
        }        
        cout<< '\n';
    }
    return 0;
}