#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int ss =s.size(), st = t.size(), all = 0, minlen = INT_MAX, rel = -1, rer = -1, len = 0, flag = false;
        if(!ss || !st)
            return "";
        int l = 0, r = 0;
        unordered_map<char, int> m, mf;
        for (int i = 0; i < st; i++){
            if(m.find(t[i]) == m.end()){
                m[t[i]] = 0;
                mf[t[i]] = 1;
            cout<<i<<' '<<t[i]<<' '<<m[t[i]]<<'\n';
                all++;
                continue;
            }
            mf[t[i]]++;
            // m[t[i]]++;
            // all++;
        }
        st = all;
        all = 0;
        while(r < ss){
            cout<<"start "<<l<<' '<<r<<'\n';
            while(r < ss && all != st){
                if(m.find(s[r]) != m.end()){
                    cout<<m[s[r]]<<' '<<s[r]<<'\n';
                    m[s[r]]++;
                    if(m[s[r]] == mf[s[r]])
                        all++;
                }
                cout<<l<<' '<<r<<' '<<all<<'\n';
                r++;
            }
            r--;
            len = r - l + 1;
            cout<<"alll "<<all<<'\n';
        if(all == st)
            flag = true;
            if(minlen > len){
                minlen = len;
                rel = l; rer = r;
            cout<<"min "<<rel<<' '<<rer<<' '<<l<<' '<<r<<' '<<minlen<<'\n';
            }
            // if(l >= r)
            //     break;
            while(l <= r){
                cout<<"in "<<'\n';
                if(m.find(s[l]) != m.end()){
                    cout<<l<<' '<<r<<' '<<'\n';
                    m[s[l]]--;
                    if(m[s[l]] < mf[s[l]]){
                        break;
                    }
                }
                l++;
            }
            len = r - l + 1;
            if(all == st && minlen > len){
                minlen = len;
                rel = l; rer = r;
            }
            cout<<"min "<<rel<<' '<<rer<<' '<<l<<' '<<r<<' '<<minlen<<'\n'<<'\n';
                        all--;
            r++; l++;
        }    
        // if(all != st) return "";
        if(!flag) return "";
        return s.substr(rel, minlen);  
    }
};

int main(){
    Solution sol;
    // cout<<sol.minWindow("Ab", "A");
    cout<<sol.minWindow("ADOBECODEBANC", "ABC");
    return 0;
}