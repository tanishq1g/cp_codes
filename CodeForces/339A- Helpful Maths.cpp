#include <iostream>
#include <string>
#include <vector>
#include <locale>

using namespace std;

int main(){
    string in;
    cin >> in;
    int s = in.size();
    int x1 = 0, x2 = 0, x3 = 0;
    for(int i = 0; i < s; i+=2){
        if(in[i] == 49)
            x1++;
        else if(in[i] == 50)
            x2++;
        else
            x3++;
    }
    string out = "";
    while(x1--)
        out += "1+";
    while(x2--)
        out += "2+";
    while(x3--)
        out += "3+";
    cout << out.substr(0, out.size() - 1);
    return 0;
}