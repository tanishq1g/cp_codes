#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
    int get(string s){
        vector<int> te(256, 0);
        int ss = s.size();
        int smch = 500;
        for(int i = 0; i < ss; i++){
            if(smch > s[i]){
                smch = s[i];
            }
            te[s[i]]++;
        }
        cout<<s<<' '<<smch<<' '<<te[smch]<<'\n';
        return te[smch];
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int sw = words.size(), sq = queries.size();
        vector<int> re;
        vector<int> fw(sw);
        for(int i = 0; i < sw; i++){
            fw[i] = get(words[i]);
        }
        int q, count;
        for(int i = 0; i < sq; i++){
            q = get(queries[i]);
            count = 0;
            for(int j = 0; j < sw; j++){
                if(q < fw[j])
                    count++;
            }
            cout<<queries[i]<<' '<<count<<'\n';
            re.push_back(count);
        }
        return re;
    }
};

int main(){
    Solution sol;
    vector<string> queries = {"bbb","cc"};
    vector<string> words = {"a","aa","aaa","aaaa"};
    vector<int> re = sol.numSmallerByFrequency(queries, words);
    return 0;
}