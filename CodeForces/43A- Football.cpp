#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    string s1, s2;
    int c1 = 1, c2 = 0;
    cin >> s;
    s1 = s;
    for(int i = 1; i < n; i++){
        cin >> s;   
        if(s1 == s){
            c1++;
        }
        else{
            s2 = s;
            c2++;   
        }
    }
    cout << ((c1 > c2) ? s1 : s2);
    return 0;
}