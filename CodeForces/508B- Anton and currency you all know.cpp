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
    string s;
    cin >> s;
    int l = s.size() - 1;
    bool nin = true;
    int t = -1;
    char ch;
    for(int i = 0; i < l; i++){
        if(s[i] % 2 == 0){
            t = i;
            if(s[i] < s[l]){
                ch = s[l];
                s[l] = s[i];
                s[i] = ch;
                cout << s;
                return 0;
            }
        }
    }
    if(t == -1)
        cout << -1;
    else{
        ch = s[l];
        s[l] = s[t];
        s[t] = ch;
        cout << s;
    }
    return 0;
}