// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
// #include <unordered_map>
// #include <string>
// using namespace std;
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int ss =s.size(), st = t.size(), all = 0, minlen = INT_MAX, rel = -1, rer = -1, len = 0, flag = false;
//         if(!ss || !st)
//             return "";
//         int l = 0, r = 0;
//         unordered_map<char, int> m, mf;
//         for (int i = 0; i < st; i++){
//             if(m.find(t[i]) == m.end()){
//                 m[t[i]] = 0;
//                 mf[t[i]] = 1;
//             cout<<i<<' '<<t[i]<<' '<<m[t[i]]<<'\n';
//                 all++;
//                 continue;
//             }
//             mf[t[i]]++;
//             // m[t[i]]++;
//             // all++;
//         }
//         st = all;
//         all = 0;
//         while(r < ss){
//             cout<<"start "<<l<<' '<<r<<'\n';
//             while(r < ss && all != st){
//                 if(m.find(s[r]) != m.end()){
//                     cout<<m[s[r]]<<' '<<s[r]<<'\n';
//                     m[s[r]]++;
//                     if(m[s[r]] == mf[s[r]])
//                         all++;
//                 }
//                 cout<<l<<' '<<r<<' '<<all<<'\n';
//                 r++;
//             }
//             r--;
//             len = r - l + 1;
//             cout<<"alll "<<all<<'\n';
//         if(all == st)
//             flag = true;
//             if(minlen > len){
//                 minlen = len;
//                 rel = l; rer = r;
//             cout<<"min "<<rel<<' '<<rer<<' '<<l<<' '<<r<<' '<<minlen<<'\n';
//             }
//             // if(l >= r)
//             //     break;
//             while(l <= r){
//                 cout<<"in "<<'\n';
//                 if(m.find(s[l]) != m.end()){
//                     cout<<l<<' '<<r<<' '<<'\n';
//                     m[s[l]]--;
//                     if(m[s[l]] < mf[s[l]]){
//                         break;
//                     }
//                 }
//                 l++;
//             }
//             len = r - l + 1;
//             if(all == st && minlen > len){
//                 minlen = len;
//                 rel = l; rer = r;
//             }
//             cout<<"min "<<rel<<' '<<rer<<' '<<l<<' '<<r<<' '<<minlen<<'\n'<<'\n';
//                         all--;
//             r++; l++;
//         }    
//         // if(all != st) return "";
//         if(!flag) return "";
//         return s.substr(rel, minlen);  
//     }
// };

// int main(){
//     Solution sol;
//     // cout<<sol.minWindow("Ab", "A");
//     cout<<sol.minWindow("ADOBECODEBANC", "ABC");
//     return 0;
// }

class Solution {
public:
    string minWindow(string s, string t) {
        int ss = s.size();
        int st = t.size();
        if(ss == 0 || st == 0)
            return "";
        unordered_map<char, pair<int, int> > umap;
        unordered_map<char, pair<int, int> >::iterator itr;

        for(int i = 0; i < st; i++){
            if(umap.find(t[i]) == umap.end()){
                umap[t[i]] = make_pair(0, 1);
            }
            else{
                umap[t[i]].second++;
            }
        }
        
        int le = 0, i = 0, mi = INT_MAX, miind = -1;
        int wh = 0;
        itr = umap.find(s[le]);
        while(le < ss && itr == umap.end()){
            le++;
            itr = umap.find(s[le]);
        }
        for(i = le; i < ss; i++){
            itr = umap.find(s[i]);
            if(itr == umap.end()){
                continue;
            }
            itr->second.first++;
            if(itr->second.first <= itr->second.second)
                wh++;
            cout << le << ' ' << i << ' ' << wh << ' ' << itr->first << ' ' << itr->second.first << ' ' << itr->second.second << '\n';
            while(le < ss && wh == st){
                if(mi > i - le + 1){
                    mi = i - le + 1;
                    miind = le;
                }
                itr = umap.find(s[le]);
                cout << "    " << le << ' ' << itr->first << ' ' << itr->second.first << ' ' << itr->second.second << '\n';
                if(itr->second.first <= itr->second.second)
                    wh--;
                itr->second.first--;
                le++;
                itr = umap.find(s[le]);
                while(le < ss && itr == umap.end()){
                    le++;
                    itr = umap.find(s[le]);
                }

            }
        }
        cout << mi << ' ' << miind << '\n';
        if(miind == -1)
            return "";
        return s.substr(miind, mi);
    }
};