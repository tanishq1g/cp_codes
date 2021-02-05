
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
#include <stack>
#include <utility>
using namespace std;

int main(){
    string ma = "abcde";
    vector<char> t{'a', 'b'};
    int m = 5, k = 2;
    int count = 0;
    vector<string> output;
    for(int i = 0; i < m; i++){
        for(int j = i; j < m; j++){
            bool ch = true;
            for(int p = i; p <= j; p++){
                bool flag = false;
                for(int q = 0; q < k; q++){
                    if(ma[p] == t[q]){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    ch = false;
                    break;
                }
            }
            if(ch){
                count++;
                output.push_back(ma.substr(i, j - i + 1));
            }
        }
    }
    cout << count << ' ' ;
    for(int i = 0; i < count; i++){
        cout << output[i] << ' ';
    }
    return 0;
}
