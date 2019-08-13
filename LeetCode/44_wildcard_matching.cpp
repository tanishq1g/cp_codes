#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
// DYNAMIC PROGRAMMING
    bool isMatch(string s, string p) {
        int ss = s.size(), sp = p.size();
        if(ss == 0 && sp == 0) return true;
        if(sp == 0)
            return false;
        vector<vector<bool> > t(ss + 1, vector<bool> (sp + 1, false));
        t[0][0] = true;
        for (int i = 1; i <= sp; i++){
            if(p[i - 1] == '*')
                t[0][i] = t[0][i - 1];
        }
        if(p[0] == '*')
            for (int i = 1; i <= ss; i++){
                    t[i][0] = true;
            }
        for (int i = 1; i <= ss; i++){
            for (int j = 1; j <= sp; j++){
                cout<<i<<' '<<j<<'\n';
                if(p[j - 1] == '?'){
                    cout<<"in1\n";
                    t[i][j] = t[i - 1][j - 1];
                }
                else if(p[j - 1] == '*'){
                    cout<<"in2\n";
                    t[i][j] = t[i][j - 1] || t[i - 1][j] || t[i - 1][j - 1];
                }
                else if(p[j - 1] == s[i - 1]){
                    cout<<"in3\n";
                    t[i][j] = t[i - 1][j - 1];
                }
                else{
                    cout<<"in4\n";
                    t[i][j] = false;
                }
            for (int x = 0; x < ss + 1; x++){
                for (int y = 0; y < sp + 1; y++)
                {
                    cout<<t[x][y]<<' ';
                }
                cout<<'\n';
            }
            cout<<'\n';
            }
        }
        return t[ss][sp];
    }
};

int main(){
    Solution sol;
    string s = "aab";
    string p = "c*a*b";
    cout<<sol.isMatch(s, p);
}