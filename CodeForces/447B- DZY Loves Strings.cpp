#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;

// bool cmp(vector<int> v1, vector<int> v2){
//     return v1
// }
int main(){
    string s;
    int k;
    // vector<vector<int>> al(26, vector<int>(2));
    vector<int> al(26);
    cin >> s >> k;
    int ma = 0;
    int ind = 0;
    int sc = 0;
    for(int i = 0; i < 26; i++){
        cin >> al[i];
        if(ma < al[i]){
            ma = al[i];
            ind = i;
        }
        // al[i][1] = i;
    }
    int l = s.size();
    for(int i = 0; i < l; i++){
        sc += al[s[i] - 97] * (i + 1);
    }
    for(int i = 0; i < k; i++){
        sc += (l + i + 1) * ma;
    }
    cout << sc;
    return 0;
}