#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

// STRING
class Solution {
    vector<string> ph{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
public:
    vector<string> letterCombinations(string digits) {
        int l = digits.size(), totalstr = 1, no;
        vector<int> lo(l);
        vector<string> re;
        
        if(!l) return re;
        for (int i = 0; i < l; i++){
            lo[i] = ph[digits[i] - 48].size();
            if(lo[i])
                totalstr *= lo[i];
        }

        string temp;        
        while(totalstr){
            temp = "";
            for (int i = 0; i < l; i++){
                no = digits[i] - 48;
                if(lo[i]){
                    temp += ph[no][ph[no].size() - lo[i]];
                }
            }
            re.push_back(temp);
            cout<<temp<<'\n';

            lo[l-1]--;
            for (int i = l - 1; i >= 0; i--)
            {
                // cout<<i<<' '<<lo[i]<<'\n';
                if(lo[i] == 0){
                    if(i - 1 >= 0)
                        lo[i - 1]--;
                    lo[i] = ph[digits[i] - 48].size();
                }
            }
            totalstr--;
        }
        return re;
    }
};

int main(){
    Solution sol;
    vector<string> re = sol.letterCombinations("23");

}