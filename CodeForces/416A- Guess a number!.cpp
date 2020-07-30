#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int l = INT_MIN, r = INT_MAX;
    bool il = false, ir = false;
    string s1, s2, s3;
    int x;
    for(int i = 0; i < n; i++){
        cin >> s1 >> s2 >> s3;
        x = stoi(s2);

        if(s3 == "N"){
            if(s1 == ">")
                s1 = "<=";
            else if(s1 == ">=")
                s1 = "<";
            else if(s1 == "<")
                s1 = ">=";
            else if(s1 == "<=")
                s1 = ">";
        }
        
        if(s1 == ">"){
            if(x > l){
                l = x;
                il = false;
            }
            else if(x == l && il){
                il = false;
            }
        }
        else if(s1 == ">="){
            if(x > l){
                l = x;
                il = true;
            }
        }
        else if(s1 == "<"){
            if(x < r){
                r = x;
                ir = false;
            }
            else if(x == r && ir){
                ir = false;
            }
        }
        else if(s1 == "<="){
            if(x < r){
                r = x;
                ir = true;
            }
        }
    // cout << l << ' ' << r << endl;
    // cout << il << ' ' << ir << endl;
    }
    if(l > r || (l == r && !(il && ir)) || (r - l == 1 && !il && !ir))
        cout << "Impossible";
    else{
        if(il)
            cout << l;
        else if( l == INT_MIN){
            if(ir)
                cout << r;
            else
                cout << r - 1;
        }
        else
            cout << l + 1;
    }
    return 0;
}