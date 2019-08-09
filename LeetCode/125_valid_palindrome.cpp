#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        char l,r;
        int f1=0,f2=0;
        for (string::iterator its = s.begin(), ite = s.end() - 1; its <= ite; its++, ite--){
            l = *its; r = *ite;
            // cout<<l<<' '<<r<<'\n';
            while(!((l >= 97 && l <= 122) || (l >= 48 && l <= 57) || (l >= 65 && l <= 90))){
                if(its == s.end() - 1){
                    f1 = 1;
                    break;
                }
                its++;
                l = *its;
                // cout<<"llll "<<l<<'\n';
            }
            while(!((r >= 97 && r <= 122) || (r >= 48 && r <= 57) || (r >= 65 && r <= 90))){
                if(ite == s.begin()){
                    f2 = 1;
                    break;
                }
                ite--;
                r = *ite;
                // cout<<"rrrr "<<r<<'\n';
            }
            if(f1 & f2)
                return true;
            if(tolower(l) != tolower(r))
                return false;
        }
        return true;
    }
};

int main(){
    string s = "./";
    Solution sol;
    cout<<sol.isPalindrome(s);
}