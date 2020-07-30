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
        int n, s;
        cin >> n >> s;
        vector<int> ve(n);        
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }

        int in = 0, sum = ve[0], flag = 0;
        for(int i = 0; i < n;){
            // cout << in << ' ' << i << ' ' << ' ' << ve[in] << ' ' << ve[i] << ' ' << sum << '\n';
            if(sum == s){
                cout << in + 1 << ' ' << i + 1<< endl;
                flag = 1;
                break;
            }
            else if(sum < s){
                i++;
                sum += ve[i];
            }
            else{
                sum -= ve[in];
                in++;
            }
        }
        if(flag)
            continue;
        cout << -1 << endl;
    }
    return 0;
}
