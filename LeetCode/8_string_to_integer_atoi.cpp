#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int num = 0, s = str.size(), off;
        bool neg = false, fnum = true, pos = false;;
        for (int i = 0; i < s; i++){
            if(str[i] == '-' && i+1 < s && str[i+1]>=48 && str[i+1]<=57){
                if(neg || !fnum)
                    break;
                neg = true;
            }
            else if(str[i] == '+' && i+1 < s && str[i+1]>=48 && str[i+1]<=57){
                if(pos)
                    break;
                pos = true;
            }
            else if(str[i]>=48 && str[i]<=57){
                cout<<num<<'\n';
                if(fnum){
                    fnum = false;
                    if(neg)
                        num = -1 * (str[i] - 48);
                    else
                        num = str[i] - 48;
                    continue;
                }
                if(neg)
                    off = -1 * (str[i] - 48);
                else
                    off = str[i] - 48;
                if(num > INT_MAX / 10 || (num == INT_MAX / 10 && off > 7)) return INT_MAX;
                if(num < INT_MIN / 10 || (num == INT_MIN / 10 && off < -8)) return INT_MIN;
                num = num * 10 + off;
            }
            else if(str[i] == ' '){
                if(num || pos || neg) break;
            }
            else{
                break;
            }
        }
        return num;
    }
};

int main(){
    Solution sol;
    string s = "0-1";
    cout<<sol.myAtoi(s);
    return 0;
}