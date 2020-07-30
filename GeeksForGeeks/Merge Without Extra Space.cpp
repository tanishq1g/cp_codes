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
        int n, m;
        cin >> n >> m;
        vector<int> v1(n), v2(m);
        for(int i = 0; i < n; i++){
            cin >> v1[i];   
        }        
        for(int i = 0; i < m; i++){
            cin >> v2[i];   
        }
        int k = 0;
        for(int i = 0, j = 0; ;){
            if(i == n){
                while(j < m){
                    cout << v2[j] << ' ';
                    j++;
                }
                break;
            }
            if(j == m){
                while(i < n){
                    cout << v1[i] << ' ';
                    i++;
                }
                break;
            }
            if(v1[i] < v2[j]){
                cout << v1[i] << ' ';
                i++;
            }
            else{
                cout << v2[j] << ' ';
                j++;
            }
        }
        cout << endl;       
    }
    return 0;
}