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

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long int> ve(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
            ve[i] = ve[i] * ve[i];
        }        
        sort(ve.begin(), ve.end());
        for(int i = 0; i < n; i++){
            cout << ve[i] << ' ';
        } cout << endl;
        bool flag = false;
        long long int x;
        for(int k = n - 1; k >= 0; k--){
            for(int i = 0, j = k - 1; i < j;){
                x = ve[i] + ve[j];
                if(x == ve[k]){
                    cout << i << ' ' << j << ' ' << k << '\n';
                    flag = true;
                    break;
                }
                if(x < ve[k])
                    i++;
                else
                    j--;
            }    
            if(flag)
                break;
        }
        if(flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}