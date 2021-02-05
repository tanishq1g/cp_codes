#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <queue>
#include <stack>
using namespace std;

int widestgap(int n, int m, vector<int> &st, vector<int> &fi){
    vector<pair<int, int>> ve(m);
    for(int i = 0; i < m; i++){
        ve[i] = pair<int, int> (st[i], fi[i]);   
    }
    sort(ve.begin(), ve.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });
    int ma = INT_MIN;
    ma = ve[0].first - 1;
    for(int i = 1; i < m; i++){
        ma = max(ve[i].first - ve[i - 1].second - 1, ma);
        ve[i].second = max(ve[i].second, ve[i - 1].second);
    }
    ma = max(n - ve[m - 1].second, ma);
    return ma;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> st(n), fi(n);
    for(int i = 0; i < m; i++){
        cin >> st[i];   
    }
    for(int i = 0; i < m; i++){
        cin >> fi[i];   
    }
    cout << widestgap(n, m, st, fi);
    return 0;
}