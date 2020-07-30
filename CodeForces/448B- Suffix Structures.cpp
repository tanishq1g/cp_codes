#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;


int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size(), l2 = s2.size(), l, ch = 26;
    vector<int> a(26, 0);
    int i, j, ind;
    for(int i = 0; i < l1; i++){
        a[s1[i] - 97]++;;
    }
    
    for(int i = 0; i < l2; i++){
        ind = s2[i] - 97;
        if(a[ind] == 0){
            cout << "need tree";
            return 0;
        }
        a[ind]--;
        if(a[ind] == 0){
            ch--;
        }
    }
    bool automation = false, tree = true;

    for(i = 0, j = 0; i < l1 && j < l2;){
        // cout << i << ' ' << j << '\n';
        if(s1[i] == s2[j]){
            i++;j++;
        }
        else{
            i++;
        }
    }
    if(j == l2){
        automation = true;
    }
    if(ch >= 0){
        tree = true;
    }
    if(automation){
        cout << "automaton";
    }
    else{
        if(l1 != l2)
            cout << "both";
        else
            cout << "array";
    }
    return 0;
}