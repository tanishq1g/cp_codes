#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

class Solution {
    vector<vector<string>> re;
    int ss;
public:
    bool check_palindrome(string &s, int in, int la){
        for (int i = in, j = la; i <= j; i++, j--){
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
    // void backtrack(string &s, int in, int la, vector<string> &tem){
    //     // cout<<in<<' '<<la<<'\n';
    //     // for(int i = 0; i < tem.size(); i++)
    //     //     cout<<tem[i]<<' ';
    //     // cout<<"<< tem \n";
    //     for (int i = in; i <= la; i++){
    //         vector<string> temp = tem;
    //         if(check_palindrome(s, in, i)){
    //             temp.push_back(s.substr(in, i - in + 1));
    //             if(i == la){
    //                 re.push_back(temp);
    //                 continue;
    //             }
    //             backtrack(s, i + 1, la, temp);
    //         }
    //     }
    // }
    // vector<vector<string>> partition(string s) {
    //     ss = s.size();
    //     if(ss == 0) return re;
    //     ss--;
    //     for (int i = 0; i <= ss; i++){
    //         vector<string> temp;
    //         if(check_palindrome(s, 0, i)){
    //             temp.push_back(s.substr(0, i + 1));
    //             if(i == ss){
    //                 re.push_back(temp);
    //                 continue;
    //             }
    //             backtrack(s, i + 1, ss, temp);
    //         }
    //     }
    //     return re;
    // }

    void backtrack(string &s, int in, int la, vector<string> &temp){
        // cout<<in<<' '<<la<<'\n';
        // for(int i = 0; i < tem.size(); i++)
        //     cout<<tem[i]<<' ';
        // cout<<"<< tem \n";
        for (int i = in; i <= la; i++){
            if(check_palindrome(s, in, i)){
                temp.push_back(s.substr(in, i - in + 1));
                if(i == la){
                    re.push_back(temp);
                    temp.pop_back();
                    continue;
                }
                backtrack(s, i + 1, la, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ss = s.size();
        vector<string> temp;
        if(ss == 0) return re;
        ss--;
        for (int i = 0; i <= ss; i++){
            if(check_palindrome(s, 0, i)){
                temp.push_back(s.substr(0, i + 1));
                if(i == ss){
                    re.push_back(temp);
                    temp.pop_back();
                    continue;
                }
                backtrack(s, i + 1, ss, temp);
                temp.pop_back();
            }
        }
        return re;
    }
};

// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> res;
//         vector<string> tmp;
//         partition(res,tmp,s);
//         return res;
//     }
//     void partition(vector<vector<string>>& res,vector<string>& tmp,string s){
//         if(!s.size())
//             if(tmp.size())res.push_back(tmp);
//         for(int i=0;i<s.size();i++){
//             int lo=0,hi=i;
//             while(lo<hi){
//                 if(s[lo]!=s[hi])break;
//                 lo++,hi--;
//             }
//             if(lo>=hi){
//                 tmp.push_back(s.substr(0,i+1));
//                 partition(res,tmp,s.substr(i+1));
//                 tmp.pop_back();
//             }
//         }
//     }
// };    

