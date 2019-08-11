#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
    // RECURSION BOTTOM UP
    vector<string> generate(string s, int n, int sc){
        cout<<"n "<<n<<"  sc "<<sc<<"  string "<<s<<'\n';
        vector<string> l1,l2;
        if(sc < 0)
            return l1;
        if(n == 1){
            if(sc == 0){
                cout<<s<<'\n';
                l1.push_back(s);
            }
            return l1;
        }
        l1 = generate(s + "(", n - 1, sc + 1);
        l2 = generate(s + ")", n - 1, sc - 1);
        l1.insert(l1.end(), l2.begin(), l2.end());
        return l1;
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> l1,l2;
        n = 2*n;
        string s = "(";
        int sc = 1;
        l1 = generate(s + "(", n - 1, sc + 1);
        l2 = generate(s + ")", n - 1, sc - 1);
        l1.insert(l1.end(), l2.begin(), l2.end());
        return l1;
    }
};

int main(){
    Solution sol;
    vector<string> re;
    re = sol.generateParenthesis(6);
    for (size_t i = 0; i < re.size(); i++)
    {
        cout<<re[i]<<'\n';
    }
    
    return 0;
}