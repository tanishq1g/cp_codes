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
    struct tra{
        vector<int> ind;
        vector<int> time;
    };
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int st = transactions.size();
        vector<string> re;
        if(st == 0)
            return re;
        
        unordered_map<string, vector<vector<int>> > umap;
        unordered_map<int, bool> ch;
        string name, time, amount, city;
        int timei, amounti;
        int j, ste;
        for(int i = 0; i < st; i++){
            name = ""; time = ""; amount = ""; city = "";
            j = 0;
            ste = transactions[i].size();
            while(transactions[i][j] != ','){
                name += transactions[i][j];
                j++;
            }
            j++;
            while(transactions[i][j] != ','){
                time += transactions[i][j];
                j++;
            }
            j++;
            timei = stoi(time);
            while(transactions[i][j] != ','){
                amount += transactions[i][j];
                j++;
            }
            j++;
            amounti = stoi(amount);
            while(j < ste){
                city += transactions[i][j];
                j++;
            }
            // cout<<i<<' '<<name<<' '<<timei<<' '<<amounti<<' '<<city<<' '<<'\n';
            if(amounti > 1000){
                re.push_back(transactions[i]);
                ch[i] = true;
                if(umap.find(name) == umap.end()){
                    vector<vector<int>> temp = {{i}, {timei}};
                    umap[name] = temp;    
                }
                else{
                    vector<vector<int>> temp = umap[name];
                    for(int k = 0; k < temp[0].size(); k++){
                        if(abs(timei - temp[1][k]) <= 60){
                            if(ch.find(temp[0][k]) == ch.end()){
                                ch[temp[0][k]] = true;
                                re.push_back(transactions[temp[0][k]]);
                            }
                            break;
                        }
                    }
                    umap[name][0].push_back(i);
                    umap[name][1].push_back(timei);
                }
                ch[i] = true;
                continue;
            }
            if(umap.find(name) == umap.end()){
                vector<vector<int>> temp = {{i}, {timei}};
                umap[name] = temp;
            }
            else{
                vector<vector<int>> temp = umap[name];
                for(int k = 0; k < temp[0].size(); k++){
                    if(abs(timei - temp[1][k]) <= 60){
                        if(ch.find(temp[0][k]) == ch.end()){
                            ch[temp[0][k]] = true;
                            re.push_back(transactions[temp[0][k]]);
                        }
                        re.push_back(transactions[i]);
                        ch[i] = true;
                        break;
                    }
                }
                umap[name][0].push_back(i);
                umap[name][1].push_back(timei);
            }
        }
        return re;
    }
};

int main(){
    Solution sol;
    vector<string> transactions = {"bob,627,1973,amsterdam","alex,387,885,bangkok","alex,355,1029,barcelona","alex,587,402,bangkok","chalicefy,973,830,barcelona","alex,932,86,bangkok","bob,188,989,amsterdam"};
    vector<string> re = sol.invalidTransactions(transactions);
    for(int i = 0; i < re.size(); i++){
        cout<<re[i]<<'\n';
    }
    return 0;
}