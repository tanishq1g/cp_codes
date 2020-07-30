#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, v;
    cin >> n >> v;
    vector<vector<int>> ve(n, vector<int>());
    vector<int> lve(n);
    int x;
    vector<int> out;
    bool inp = false;
    for(int i = 0; i < n; i++){
        cin >> x;
        lve[i] = x;
        inp = false;
        for(int j = 0; j < lve[i]; j++){
            cin >> x;
            ve[i].push_back(x);
            if(v > x)
                inp = true;
        }
        if(inp){
            out.push_back(i + 1);
        }
    }
    cout << out.size() << endl;
    for(int i = 0; i < out.size(); i++){
        cout << out[i] << ' ';
    }
    return 0;
}