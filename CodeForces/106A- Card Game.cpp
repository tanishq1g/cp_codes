#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;


int main(){
    char t;
    string c1, c2;
    cin >> t >> c1 >> c2;
    string r = "6789TJQKA";
    if(c1[1] == t && c2[1] == t){
        if(r.find(c1[0]) > r.find(c2[0]))
            cout << "YES";
        else
            cout << "NO";
    }
    else if(c1[1] == t)
        cout << "YES";
    else if(c2[1] == t)
        cout << "NO";
    else if(c1[1] == c2[1])
        if(r.find(c1[0]) > r.find(c2[0]))
            cout << "YES";
        else
            cout << "NO";
    else    
        cout << "NO";
    return 0;
}