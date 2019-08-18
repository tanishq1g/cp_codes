
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
    static bool comparator(string x, string y){
        return lexicographical_compare(x.begin(),x.end(),y.begin(),y.end());
    }
public:
    // string lastSubstring(string s) {
    //     int ss = s.size();
    //     if(ss == 0)
    //         return "";
    //     vector<string> all;
    //     for(int i = 0; i < ss; i++){
    //         for(int j = i; j < ss; j++){
    //             all.push_back(s.substr(i, j - i + 1));
    //         }
    //     }
    //     cout<<all.size()<<'\n';
    //     sort(all.begin(), all.end(), comparator);
    //     // for(int i = 0; i < all.size(); i++){
    //     //     cout<<all[i]<<' ';
    //     // }
    //     cout<<'\n';
    //     return all[all.size() - 1];
    //     // return *all.end();
    // }
    string lastSubstring(string s) {
        int ss = s.size();
        if(ss == 0 || ss == 1)
            return s;
        // int curr = 0, j, k;
        // vector<vector<int>> compare(ss, vector<int>(ss, )); 
        // for(int i = 0; i < ss; i++){
        //     cout<<i<<' '<<curr<<'\n';
        //     if(s[i] > s[curr]){
        //         curr = i;
        //     }    
        //     else if(s[i] == s[curr]){
        //         cout<<"  in\n";
        //         for(j = curr, k = i; j < i && k < ss; j++, k++){
        //             cout<<"  "<<j<<' '<<k<<'\n';
        //             if(s[j] > s[k]){
        //                 break;
        //             }
        //             else if(s[j] < s[k]){
        //                 curr = i;
        //                 break;
        //             }
        //         }
        //         cout<<"     "<<curr<<'\n';
        //     }
        // }
        // string str = "";
        // for(int i = 0; i < ss; i++){
        //     str = max(str, s.substr(i));
        // }
        // return str;
        string re = "";
        re = s[3];
        cout<<re<<'\n';
        for(int i = ss - 1; i >= 0; i--){
            if(re < s.substr(i, i + re.size()))
                re = s.substr(i); 
        }
        return re;
    }
};

// 
class Solution {
public:
    string lastSubstring(string s) {
        int mx = 0;
        int start = -1;
		//find largest char
        for(int i = 0; i < s.size(); i++){
            mx = max(mx, s[i]-'a');
        }
        char c = 'a'+mx;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == c){
                if(start == -1){
                    start = i;
                }else{
                    //Check if we need to update start i.e if prev(start..) substring is less than new(i..)
                    int prev = start+1;
                    int nw = i+1;
                    while(nw < s.size()){
                        if(s[prev] < s[nw]){
                            start = i;
                        }else if(s[prev] > s[nw]){
                            break;
                        }
                        prev++;
                        nw++;
                    }
                }

                // ==============================================================================forgot this
                //We will find the first occurence of 'c' that is followed by a different char, because that is what we would like to test next
                while(i < s.size() && s[i] == c) i++;
                i--;
            }
        }
        return s.substr(start);
    }
};


int main(){
    Solution sol;
    // vector<string> words {"catc","bt","hat","tree"};
    string chars = "abab";
    cout<<sol.lastSubstring(chars);
}
