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
    int strStr(string haystack, string needle) {
        int l1 = haystack.size();
        int l2 = needle.size();
        if(l2 == 0)
            return 0;
        if(l2 > l1){
            return -1;
        }
        int x = -1;
        for (size_t i = 0; i < l1 - l2 + 1; i++){
            if(haystack[i] == needle[0]){
                if(needle == haystack.substr(i, l2)){
                    x = i;
                    break;
                }
            }
        }
        return x;
    }
};
void main(){
    string haystack, needle;
    cin >> haystack >> needle;
    Solution sol;
    cout << sol.strStr(haystack, needle);
}