#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
// DYNAMIC PROGRAMMING
    bool isMatch(string s, string p) {
        // one indexing
        int ss = s.size(), sp = p.size();
        bool t[ss+1][sp+1];
        t[0][0] = true;

        // for a*, a*b* types
        for(int j = 1;j <= sp; j++){
            t[0][j] = false;
            if(p[j-1] == '*'){
                if(j-2>=0)
                    t[0][j] = t[0][j-2];
            }
        }

        for(int i = 1; i <= ss; i++){
            t[i][0] = false;
        }

        for(int i = 1; i <= ss; i++){
            cout<<'\n';
            for(int j = 1; j <= sp; j++){
                if(p[j-1] != '*'){
                    if(p[j-1] == '.' || s[i-1] == p[j-1])
                        t[i][j] = t[i-1][j-1];
                    else
                        t[i][j] = false;
                }
                else{
                    if(j-2 >=0 && t[i][j-2])
                        t[i][j] = true;
                    else if(p[j-2] == '.' || s[i-1] == p[j-2])
                        t[i][j] = t[i-1][j];
                    else
                        t[i][j] = false;
                }
                cout<<"i "<<i<<" j "<<j<<"   t[i][j] "<<t[i][j]<<'\n';
            }
        }
        return t[ss][sp];
    }
};

int main(){
    Solution sol;
    string s1 = "aab";
    string s2 = "c*a*b";
    cout<<sol.isMatch(s1,s2);
    return 0;
}