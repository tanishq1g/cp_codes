#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    string s, out = "";
    cin >> s;
    int l = s.size();
    for(int i = 0; i < l; ){
        if(s[i] == 'W' && i + 1 < l && s[i + 1] == 'U' && i + 2 < l && s[i + 2] == 'B'){
            i += 3;
            if(out.size() != 0 && i < l)
                out += " ";
        }
        else{
            out += s[i];
            i++;
        }  
    }
    cout<<out;
    return 0;
}