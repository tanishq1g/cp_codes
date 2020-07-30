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

// STRING

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> ve(n);
        int smi = INT_MAX, ss;
        for(int i = 0; i < n; i++){
            cin >> ve[i]; 
            ss = ve[i].size();
            smi = min(smi, ss);   
        }
        int flag = 0, i;
        for( i = 0; i < smi; i++){
            for(int j = 1; j < n; j++){
                if(ve[j][i] != ve[j - 1][i]){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(i == 0)
            cout << -1 << endl;
        else
            cout << ve[0].substr(0, i) << endl;
    }
    return 0;
}