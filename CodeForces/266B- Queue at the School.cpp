#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    char ch;
    for(int i = 0; i < t; i++){
        for(int j = n - 1; j > 0; j--){
            if(s[j] == 'G' && s[j - 1] == 'B'){
                s[j] = 'B';
                s[j - 1] = 'G';
                j--;
            // cout <<i<<' '<< j<<' '<< s << endl;
            }
        }
    }
    cout << s;
    return 0;
}