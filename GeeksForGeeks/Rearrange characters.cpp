#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <climits>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// HEAPS

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ss = s.size();
        bool flag;
        for(int i = 1; i < ss; i++){
            if(s[i] == s[i - 1]){
                flag = true;
                for(int j = i + 1; j < ss; j++){
                    if(s[j] != s[i]){
                        swap(s[j], s[i]);
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            cout << i << ' ' << s << '\n';
            }
        }
        for(int i = ss - 1; i > 0; i--){
            if(s[i] == s[i - 1]){
                flag = true;
                for(int j = i - 2; j >= 0; j--){
                    if(s[j] != s[i]){
                        swap(s[j], s[i - 1]);
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            cout << i << ' ' << s << '\n';
            }
        }        
        cout << s << '\n';
        if(flag){
            cout << 0 << '\n';
        }
        else{
            cout << 1 << '\n';
        }
    }
    return 0;
}