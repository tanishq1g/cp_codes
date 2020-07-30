#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    vector<int> v(26, 0);
    int ss = s.size(), count;
    for(int i = 0; i < ss; i++){
            // cout<<s[i]<<'\n';
        if(s[i] >= 97 && s[i] <= 122){
            if(v[s[i] - 97] == 0){
                count++;
            }
            v[s[i] - 97]++;
        }
    }
    cout<<count;
    return 0;
}