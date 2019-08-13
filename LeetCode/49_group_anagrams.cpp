#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > m;
        vector<vector<string> > re;
        
        string strsort;
        for (int i = 0; i < strs.size(); i++){
            strsort = strs[i];
            sort(strsort.begin(), strsort.end());
            m[strsort].push_back(strs[i]);
        }
        for (auto it = m.begin(); it != m.end(); it++){
            re.push_back(it -> second);
        }
        return re;
    }
};

int main(){
    Solution sol;
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    sol.groupAnagrams(strs);
}