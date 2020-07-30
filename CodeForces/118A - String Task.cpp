#include <iostream>
#include <string>
#include <vector>
#include <locale>

using namespace std;

int main(){
    string vowels = "AEIOUYaeiouy";
    string in, out = "";
    cin >> in;
    int len = in.size();
    for(int i = 0; i < len; i++){
        if(vowels.find(in[i]) != -1){
            continue;
        }
        else if(in[i] < 97){
            out += ".";
            out += in[i] + 32;
        }
        else{
            out += ".";
            out += in[i];
        }
    }
    cout<<out;
    return 0;
}