#include <iostream>
#include <string>
#include <vector>
#include <locale>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size(), l2 = s2.size();
    for(int i = 0; i < l1 && i < l2; i++){
        if(s1[i] < 97)
            s1[i] += 32;
        if(s2[i] < 97)
            s2[i] += 32;
        if(s1[i] == s2[i])
            continue;
        if(s1[i] < s2[i]){
            cout << -1;
            return 0;
        }
        if(s1[i] > s2[i]){
            cout << 1;
            return 0;
        }
    }
    if(l1 < l2)
        cout << -1;
    else if(l1 > l2)
        cout << 1;
    else
        cout << 0;
    return 0;
}