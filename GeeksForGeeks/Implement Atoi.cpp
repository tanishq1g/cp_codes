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

// STRING

int atoi(string s){
    int ss = s.size();
    int ret = 0;
    int la = 0;
    if(s[0] == '-'){
        la = 1;
    }
    for(int i = ss - 1, j = 0; i >= la; i--, j++){
        if(s[i] >= '0' && s[i] <= '9'){
            ret += (s[i] - '0') * pow(10, j);
        }
        else{
            return -1;
        }
    }
    if(la == 1){
        ret *= -1;
    }
    return ret;
}