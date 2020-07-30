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
    int n;
    cin >> n;
    vector<vector<int>> ve(n, vector<int>(2));
    unordered_map<int, int> umap;
    for(int i = 0; i < n; i++){
        cin >> ve[i][0] >> ve[i][1];
        if(umap.find(ve[i][0]) == umap.end()){
            umap[ve[i][0]] = 1;
        }   
        else{
            umap[ve[i][0]]++;;
        }
    }
    int k;
    for(int i = 0; i < n; i++){
        if(umap.find(ve[i][1]) == umap.end()){
            cout << n - 1 << ' ' << n - 1 << endl;
        }     
        else{
            k = umap[ve[i][1]];
            // cout << k << endl;
            cout << n - 1 + k << ' ' << n - 1 - k << endl;
        }
    }
    return 0;
}