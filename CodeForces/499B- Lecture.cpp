#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string a, b;
    unordered_map<string, string> umap;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        umap[a] = b;
    }
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a.size() <= umap[a].size())
            cout << a << ' ';
        else
            cout << umap[a] << ' ';  
    }
    return 0;
}