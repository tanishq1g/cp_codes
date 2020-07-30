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

// array

auto cmp = [](const int &a, const int &b){
    return a >= b;
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ve(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }        
        int ma = INT_MIN;
        vector<int> out;
        for(int i = n - 1; i >= 0; i--){
            if(ve[i] >= ma){
                ma = max(ma, ve[i]);
                out.push_back(ve[i]);
            }
        }
        for(int i = out.size() - 1; i >= 0 ; i--){
            cout << out[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}