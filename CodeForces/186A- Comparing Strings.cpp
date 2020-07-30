#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size(), l2 = s2.size();
    if(l1 != l2){
        cout << "NO";
        return 0;
    }
    vector<int> ve;
    int ctr = 0;
    for(int i = 0; i < l1; i++){
        if(s1[i] != s2[i]){
            ve.push_back(i);
            ctr++;
        }
        if(ctr > 2){
            cout << "NO";
            return 0;
        }
    }
    if(ctr == 1 || (ctr == 2 && !(s1[ve[0]] == s2[ve[1]] && s1[ve[1]] == s2[ve[0]]))){
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}