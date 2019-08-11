#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> curind(256, -1);
        int len = s.size();
        if(!len)
            return 0;
        int maxlen = 0;
        int in = 0, la = 0, newin;
        for (int i = 0; i < len; i++){
            if(curind[s[i]] == -1){
                la = i;
                curind[s[i]] = i;
            }
            else{
                newin = curind[s[i]] + 1;
                la = i;
                for(int j = in; j < newin; j++){
                    curind[s[j]] = -1;
                }
                curind[s[i]] = i;
                in = newin;
            }
            maxlen = max(maxlen, la - in + 1);
            // cout<<s[i]<<" in "<<in<<" la "<<la<<" maxlen "<<maxlen<<"\n";
        }
        return maxlen;
    }
};

int main(){
    Solution sol;
    string s = "abcabcbb";
    cout<<sol.lengthOfLongestSubstring(s);
    return 0;
}