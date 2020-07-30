#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
#include <climits>
using namespace std;

int main(){
    int m, s;
    cin >> m >> s;
    
    if(m == 1 && s <= 9){
        cout << s << ' ' << s;
        return 0;
    }

    string ss = "", ss2 = "";
    int s2 = s - 1;

    for(int i = 1; i <= m; i++){
        if(s > 9){
            ss += "9";
            s -=9;
        }
        else{
            ss += to_string(s);
            s = 0;
        }
    }
    if(s > 0 || ss[0] == '0'){
        cout << -1 << ' ' << -1;
        return 0;
    }
    s = s2;
    ss2 = ss;
    ss = "";
    for(int i = 1; i <= m; i++){
        if(s > 9){
            ss += "9";
            s -=9;
        }
        else{
            ss += to_string(s);
            s = 0;
        }
    }
    reverse(ss.begin(), ss.end());
    // cout << type(char(stoi(ss.substr(0, 1)) + 1)) << endl;
    // cout << (stoi(ss.substr(0, 1)) + 1) << ' ';
    ss[0] = char(stoi(ss.substr(0, 1)) + 1 + 48);
    cout << ss << ' ' << ss2;
    return 0;
}