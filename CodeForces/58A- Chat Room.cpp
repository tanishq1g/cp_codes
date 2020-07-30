#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
using namespace std;

int main(){
    string s, wo = "hello";
    cin >> s;
    int l = s.size();
    for(int i = 0, j = 0; i < l; i++){
        if(s[i] == wo[j]){
            j++;
            if(j == 5){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
