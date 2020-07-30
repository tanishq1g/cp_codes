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
        if(a.second < b.second)
            return true;
        return false;
    }
};

int main(){
    set<pair<int, int>, cmp> st;
    set<pair<int, int> > :: iterator itr, miitr;
    pair<int, int> p;
    p = make_pair(0, 100);
    st.insert(p);
    cout << st.size() << '\n';
    p = make_pair(1, 100);
    st.insert(p);

    cout << st.size() << '\n';
    for(itr = st.begin(); itr != st.end(); itr++){
        cout << itr->first << ' ' << itr->second << ' ' << &itr<<'\n';
    }

    p = make_pair(1, 100);
    itr = st.find(p);
    cout << itr->first << ' ' << itr->second << ' ' << &itr << '\n';

    st.erase(itr);
    for(itr = st.begin(); itr != st.end(); itr++){
        cout << itr->first << ' ' << itr->second << '\n';
    }
    return 0;
}