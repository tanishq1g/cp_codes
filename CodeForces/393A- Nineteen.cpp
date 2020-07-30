#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> ve(4,0);
    int l = s.size();
    for(int i = 0; i < l; i++){
        if(s[i] == 'n')
            ve[0]++;
        else if(s[i] == 'i')
            ve[1]++;
        else if(s[i] == 'e')
            ve[2]++;
        else if(s[i] == 't')
            ve[3]++;
    }
    int t = min(ve[1], min(ve[2] / 3, ve[3]));
    if(t == 0)
        cout << 0;
    else if(ve[0] >= (3 * t - t + 1))
        cout << t;
    else
        cout << (ve[0] % 2 == 1 ? ve[0] / 2 : (ve[0] / 2) - 1);
    return 0;
}