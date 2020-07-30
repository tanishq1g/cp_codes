#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s, out;   
    while(n--){
        cin >> s;
        int l = s.size();
        out = "";
        if(l <= 10){
            cout << s << "\n";
            continue;
        }
        out += s[0] + to_string(l - 2) + s[l-1];
        cout<<out << "\n";
    }
    return 0;
}