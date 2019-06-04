#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;


class Solution {
public:
// VERTICAL SCANNING

    // string longestCommonPrefix(vector<string>& strs) {
    //     if (strs.size() == 0) return "";

    //     string out = "", temp = "";
    //     bool flag = false; 
    //     int j = 0;

    //     while(j >= 0){
    //         for (int i = 0; i < strs.size() - 1; i++){
    //             if(!strs[i][j]){
    //                 flag = true;
    //                 cout << "in1 ";
    //                 break;
    //             }
    //             if(strs[i][j] != strs[i+1][j]){
    //                 flag = true;
    //                 break;
    //             }
    //             temp = strs[i][j];
    //             cout<<j << ' ' << i << ' ' << out << ' ' << strs[i] << '\n';
    //         }
    //         cout << "outsdsasd\n";
    //         if(flag){
    //             break;
    //         }
    //         else{
    //             out += temp;
    //         }
    //         j++;
    //     }
    //     return out;
    // }


// DIVIDE AND CONQUER

    // string first_common_substring(string s1, string s2){
    //     cout << "fcb ";
    //     int i = 0;
    //     string out = "";
    //     int mlen = min(s1.size(), s2.size());
    //     while(i < mlen){
    //         if(s1[i] == s2[i]){
    //             out += s1[i];
    //         }
    //         else{
    //             break;
    //         }
    //         i++;
    //     }
    //     cout << "out: " << out << '\n';
    //     return out;
    // }

    // string rec_prefix(vector<string>& strs, int in, int la){
    //     cout << in << ' ' << la<<'\n';
    //     if(la == in){
    //         return strs[in];
    //     }
    //     else{
    //         int mid = (la + in) / 2;
    //         string str1, str2;
    //         str1 = rec_prefix(strs, in, mid);
    //         str2 = rec_prefix(strs, mid + 1, la);
    //         return first_common_substring(str1, str2);
    //     }
    // }

    // string longestCommonPrefix(vector<string>& strs) {
    //     if (strs.size() == 0) return "";
    //     return rec_prefix(strs, 0, strs.size() - 1);        
    // }

// BINARY SEARCH

    bool isCommonPrefix(vector<string>& strs, int strlen){
        string strch = strs[0].substr(0, strlen);
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].substr(0, strlen) != strch){
                return false;
            }
        }
        return true;
    } 
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int minlen = INT_MAX;
        for (int i = 0; i < strs.size(); i++){
            int strlen = strs[i].size();
            minlen = min(minlen, strlen);
        }
        int in = 0, la = minlen;
        while(in <= la){
            int mid = (la + in) / 2;
            if(isCommonPrefix(strs, mid)){
                in = mid + 1;
            }
            else{
                la = mid - 1;
            }
        }
        return strs[0].substr(0, (la + in) / 2);        
    }

};

int main() {
	Solution sol;
	vector<string> strs = {"flower","flow","flight"};
	// vector<string> strs = {"dog","racecar","car","cat"};
	cout << sol.longestCommonPrefix(strs);	
	return 0;
}