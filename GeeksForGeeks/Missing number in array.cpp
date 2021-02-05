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
#define INF 1e7

// array


https://stackoverflow.com/questions/3492302/easy-interview-question-got-harder-given-numbers-1-100-find-the-missing-numbe

https://www.geeksforgeeks.org/sum-of-kth-powers-of-first-n-natural-numbers/


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ve(n);
        int su = 0;
        for(int i = 1; i < n; i++){
            cin >> ve[i];   
            su += ve[i];
        }
        cout << (n * (n + 1) / 2) - su << '\n';

    }
    return 0;
}