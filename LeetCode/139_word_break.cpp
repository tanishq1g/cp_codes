#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

class Solution {
    int ss;
    bool check(unordered_map<int, vector<int> > &m, int chind){
        cout<<"chind "<<chind<<'\n';
        if(chind == ss)
            return true;
        bool temp;
        if(m.find(chind) != m.end()){
            int s = m[chind].size();
            cout<<s<<'\n';
            for (int i = 0; i < s; i++){
                temp = check(m, chind + m[chind][i]);
                cout<<"   infor "<<chind<<' '<<i<<' '<<temp<<'\n';
                if(temp)
                    return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        ss = s.size();
        int sw = wordDict.size();
        if(ss == 0 || sw == 0)
            return false;
        cout<<ss<<' '<<sw<<'\n';
        unordered_map<int, vector<int>> m;
        int f = -1, k = 0;
        int t1,t2;
        vector<bool> flag(ss, false); 
        for (int i = 0; i < sw; i++){
            k = 0;
            f = s.find(wordDict[i]);
            while(f != -1){
                f = f + k;
                cout<<"in "<<wordDict[i]<<' '<<f<<'\n';
                if(m.find(f) != m.end()){
                    cout<<"asdf"<<f<<'\n';
                    for (int j = 0; j < m[f].size(); j++)
                    {
                        cout<<m[f][j]<<'\n';
                    }
                    
                    m[f].push_back(wordDict[i].size());
                }
                else{
                    m[f] = vector<int>(1, wordDict[i].size());
                    cout<<" in12 "<<m[f][0]<<'\n';
                    // m[f].push_back(wordDict[i].size());
                }
                t1 = f;
                t2 = wordDict[i].size() + f;
                while(t1 < t2){
                    cout<<"in while "<<t1<<'\n';
                    flag[t1] = true;
                    t1++;
                }
                                
                if(f + 1 < ss){
                    k = f + 1;
                    cout<<"  in2  "<<s.substr(f + 1)<<'\n';
                    f = s.substr(f + 1).find(wordDict[i]);
                }
                else
                    break;
            }
        }
        for (int j = 0; j < ss; j++)
        {
            if(!flag[j])
                return false;
        }
        
        for (unordered_map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++){
            cout<<"itt  "<<it->first<<'\n';
            vector<int> te = it->second;
            for (int j = 0; j < te.size(); j++){
                cout<<te[j]<<' ';
            }
            cout<<'\n';
        }
        
        return 0;
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int lo = 0, hi, maxWordLength = 0;
        unordered_set<string> dict;
        unordered_set<int> valid;
        for (auto word: wordDict) {
            dict.insert(word);
            maxWordLength = max(maxWordLength, (int)word.size());
        }
        valid.insert(-1);
        for (int lo = 0; lo < s.size(); lo++) 
            if (valid.count(lo-1)) {
                string word = ""; hi = lo;
                while (hi < s.size() && hi - lo <= maxWordLength) {
                    word += s[hi];
                    if (dict.count(word)) valid.insert(hi);
                    hi++;
                }
            }
        return valid.count(s.size() - 1);
    }
};


int main(){
    Solution sol;
    vector<string> vec = {"aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"};
    cout<<sol.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", vec);
    return 0;
}