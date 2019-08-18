#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sc = chars.size(), sw = words.size();
        if(sc == 0 || sw == 0){
            return 0;
        }   
        unordered_map<char, int> umap1, umap2;     
        for(int i = 0; i < sc; i++){
            if(umap1.find(chars[i]) == umap1.end()){
                umap1[chars[i]] = 1;
                umap2[chars[i]] = 1;
            }
            else{
                umap1[chars[i]]++;
                umap2[chars[i]]++;
            }
            cout<<chars[i]<<" in chars \n";
        }
        int sww = 0, count = 0;
        bool flag = true;
        for(int i = 0; i < sw; i++){
            sww = words[i].size();
            flag = true;
            for(auto it1 = umap1.begin(), it2 = umap2.begin(); it1 != umap1.end(); it1++, it2++){
                it1->second = it2->second;
            }
            for(int j = 0; j < sww; j++){
                cout<<words[i][j]<<'\n';
                if(umap1.find(words[i][j]) == umap1.end()){
                    flag = false;
                    break;
                }
                else{
                    if(umap1[words[i][j]] == 0){
                        flag = false;
                        break;
                    }
                    umap1[words[i][j]]--;
                }
            }
            cout<<flag<<'\n';
            if(flag)
                count += sww;
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<string> words {"catc","bt","hat","tree"};
    string chars = "atach";
    cout<<sol.countCharacters(words, chars);
}
