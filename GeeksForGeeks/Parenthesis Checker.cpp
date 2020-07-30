#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// STACK AND HEAPS

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        stack<char> st;
        int ss = s.size();
        for(int i = 0; i < ss; i++){
            if(s[i] == '}'){
                if(!st.empty()){
                    if(st.top() == '{'){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    if(st.top() == '('){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
            else if(s[i] == ']'){
                if(!st.empty()){
                    if(st.top() == '['){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }        
        if(st.empty())
            cout << "balanced\n";
        else
            cout << "not balanced\n";
    }
    return 0;
}
