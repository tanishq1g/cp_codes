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
#include <deque>
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// STACK AND HEAPS


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> ve(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }
        deque<int> dq;
        int i = 0;
        for( ; i < k; i++){
            while(!dq.empty() && ve[i] >= ve[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            // cout << " ele " << ve[i] << ' ' << i << '\n';
            // for(auto itr = dq.begin(); itr != dq.end(); itr++){
            //     cout << *itr << ' ' ;
            // }cout << '\n';
        }
        for( ; i < n; i++){
            cout << ve[dq.front()] << ' ';
            while(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }
            while(!dq.empty() && ve[i] >= ve[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            // cout << " ele " << ve[i] << ' ' << i << '\n';
            // for(auto itr = dq.begin(); itr != dq.end(); itr++){
            //     cout << *itr << ' ' ;
            // }cout << '\n';
        }
        cout << ve[dq.front()] << '\n';
    }
    return 0;
}