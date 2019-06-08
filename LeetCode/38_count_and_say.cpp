#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
    string str[31];
public:
    Solution(){
        str[1] = "1";
    }
    string say(string st){
        // cout << "say"<<st << '\n';
        // cout <<st.size()<<' '<< ((int)st[st.size() - 1] - 48 + 1) << ' ' << st << '\n';
        st += char((((int)st[st.size() - 1] - 48 + 1) % 10) + 48);
        // cout <<st.size()<<' '<< ((int)st[st.size() - 2] - 48 + 1) << ' ' << st << '\n';
        string out = "";
        int j = 1;
        for (size_t i = 0; i < st.size() - 1; i++){
            // cout << i << ' ';
            if(st[i] == st[i+1]){
                // cout << "add " << j << ' ';
                j++;
            }
            else{
                // cout << "else " << char(j + 48) << ' ' << out << ' '; 
                out += char(j + 48);
                out += st[i];
                // cout << out;S
                j = 1;
            }
            // cout << '\n';
        }
        // cout << out << "end\n";
        return out;
        
    }
    string countAndSay(int n) {
        // cout << "countAndSay"<< n << '\n';
        if(!str[n].empty()){
            return str[n];
        }
        else{
            if(!str[n-1].empty()){
                str[n] = say(str[n-1]);
            }
            else{
                str[n-1] = countAndSay(n-1);
                str[n] = say(str[n-1]);                
            }
        }
        return str[n];
    }
};

void main(){
    // char a = '1';
    // cout << int(a) << ' ' << (int)a << (int)'0' << ' '<<char(48);
    Solution sol;
    cout << sol.countAndSay(5);
}