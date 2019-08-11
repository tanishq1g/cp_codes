#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 1) return s;
        if(len == 0) return s;
        if(len == 2){
            if(s[0] == s[1]) return s;
            else return s.substr(0,1);
        }

        len--;
        int curr = 1, in = 1, la = 1, rin = -1, rla = -1, maxlen = 0, curlen= 0, evenpal = false, oddpal = false;
        if(s[0] == s[1]){
            rin = 0;
            rla = 1;
            maxlen = 2;
        }
        if(s[curr] == s[curr + 1]){
            cout<<"evenpal\n";
            evenpal = true;
            in = curr;
            la = curr + 1;
            curlen = la - in + 1;
            if(maxlen < curlen){
                rin = in;
                rla = la;
                maxlen = curlen;
            }
        }
        while(curr < len){
            cout<<curr<<' '<<s[curr]<<" in "<<in<<" la "<<la<<" rin "<<rin<<" rla "<<rla<<" maxlen "<<maxlen<<"   evenpal "<<evenpal<<" oddpal "<<oddpal<<'\n';
            if(s[in - 1] == s[la + 1]){
                cout<<"in\n";
                in--;
                la++;
                curlen = la - in + 1;
                if(maxlen < curlen){
                    rin = in;
                    rla = la;
                    maxlen = curlen;
                }
            }
            else{
                if(evenpal && oddpal){
                    evenpal = false;
                    oddpal = false;
                    curr++;
                    in = curr;
                    la = curr;
                    oddpal = true;
                }
                else if(evenpal){
                    la = curr;
                    in = curr;
                    oddpal = true;
                }
                else{
                    if(curr+1 <= len && s[curr] == s[curr + 1]){
                        evenpal = true;
                        cout<<"evenpal\n";
                        evenpal = true;
                        in = curr;
                        la = curr + 1;
                        curlen = la - in + 1;
                        if(maxlen < curlen){
                            rin = in;
                            rla = la;
                            maxlen = curlen;
                        }
                    }
                    else{
                        oddpal = false;
                        curr++;
                        in = curr;
                        la = curr;
                    }
                }
            }
            if(in == 0 || la == len){
                if(evenpal && oddpal){
                    evenpal = false;
                    oddpal = false;
                    curr++;
                    in = curr;
                    la = curr;
                    oddpal = true;
                }
                else if(evenpal){
                    la = curr;
                    in = curr;
                    oddpal = true;
                }
                else{
                    if(curr+1 <= len && s[curr] == s[curr + 1]){
                        evenpal = true;
                        cout<<"evenpal\n";
                        evenpal = true;
                        in = curr;
                        la = curr + 1;
                        curlen = la - in + 1;
                        if(maxlen < curlen){
                            rin = in;
                            rla = la;
                            maxlen = curlen;
                        }
                    }
                    else{
                        oddpal = false;
                        curr++;
                        in = curr;
                        la = curr;
                    }
                }
            }
        }
        if(rin == -1) return s.substr(0,1);
        return s.substr(rin, maxlen);
    }
};

int main(){
    Solution sol;
    string s = "abcdbbfcba";
    cout<<sol.longestPalindrome(s);
    return 0;
}