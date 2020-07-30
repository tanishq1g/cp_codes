#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;

// string s;
// int binary_search(vector<int> &a, int val){
//     // cout << "   " << a.size() << ' ' << val << endl;
//     int s = 0, sa = a.size();
//     if(a[0] > val){
//         return a[0];
//     }
//     if(a[sa - 1] < val){
//         return a[sa - 1];
//     }
//     int l = sa - 1, m;
//     while(s <= l){
//         m = (s + l) / 2;
//         // cout << "    "<<s << ' ' << m << ' ' << l << endl;
//         if(a[m] == val){
//             return a[m];
//         }
//         else if(a[m] < val){
//             s = m + 1;
//         }
//         else{
//             l = m - 1;
//         }
//     }
//     if(a[l] < val){

//         return a[l + 1];
//     }
//     else{
//         return a[l - 1];
//     }
//     return a[l];
// }

// void output(int &turn){

//     if(turn % 2 == 0){
//         cout << "First";
//     }
//     else
//         cout << "Second";
// }

// int func(vector<vector<int>> &ve, int ii, int jj, int turn = 0){
//     int x, y, ind1, ind2;
//     bool nx = false, ny = false;
//     for(int i = ii, j = jj; i < j;){
//         cout << i << ' ' << j << '\n';
//         if(s[i] == s[j]){
//             cout << "------------------ " << s[i] << '\n';
//             i++;j--;
//         }
//         else{
//             nx = false, ny = false;
//             ind1 = s[i] - 97;
//             ind2 = s[j] - 97;
//             x = binary_search(ve[ind1], j - 1);
//             y = binary_search(ve[ind2], i + 1);
//             cout << ' ' << x << ' ' << y << '\n';
//             if(x <= i || x >= j){
//                 nx = true;
//             }
//             if(y <= i || y >= j){
//                 ny = true;
//             }
//             if(nx && ny){
//                 if(j - i == 1){
//                     turn = (turn + 1);
//                     return turn;
//                     // output(turn);
//                     // return 0;
//                 }
//                 turn = (turn + 2);
//                 i++;j--;
//             }
//             else if(nx){
//                 i++;
//                 turn = (turn + 1);
//             }
//             else if(ny){
//                 j--;
//                 turn = (turn + 1);
//             }
//             else{
//                 if(j - x < y - i){
//                     j--;
//                 }
//                 else if(j - x == y - i){
//                     cout <<"SWITCH\n";
//                     return min(func(ve, i, j - 1, turn + 1), func(ve, i + 1, j, turn + 1));
//                 }
//                 else{
//                     i++;
//                 }
//                 turn = (turn + 1);
//             }
//         }
//     }
//     cout << turn << '\n';
//     return turn;
// }

// int main(){
//     cin >> s;
//     int l = s.size();
//     vector<vector<int>> ve(26, vector<int>());
//     int ind;
//     for(int i = 0; i < l; i++){
//         ind = s[i] - 97;
//         ve[ind].push_back(i);
//     }
//     int turn = func(ve, 0, l - 1);
//     output(turn);
//     return 0;
// }

string s;
int cnt[30];
int main()
{
   
        cin>>s;
        for (int i=0; i<s.size(); ++i)
                cnt[s[i]-'a']++;
        int odd=0;
        for (int i=0; i<26; ++i)
                if (cnt[i]&1)
                        odd++;
        if ((odd==0) || (odd&1))
                cout<<"First"<<endl;
        else
                cout<<"Second"<<endl;
    return 0;
}