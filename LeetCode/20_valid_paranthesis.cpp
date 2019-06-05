#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        cout<<"in";
        stack <char> st;
        for (int i = 0; i < s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if((st.top() == '(') && (s[i] == ')')){
                st.pop();
            }
            else if((st.top() == '[') && (s[i] == ']')){
                st.pop();
            }
            else if((st.top() == '{') && (s[i] == '}')){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            cout<<st.top()<<'\n';
        }    
        if(st.empty()){
            return true;
        }    
        else{
            return false;
        }
    }
};

int main(){
    string s;
    cin >> s;
    Solution sol;
    bool l = sol.isValid(s);
    cout << "sd" << l;
    return 0;
}