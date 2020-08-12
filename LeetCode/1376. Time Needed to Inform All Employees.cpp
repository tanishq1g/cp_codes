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

// array 

class Solution {
public:
    int dfs(vector<vector<int> > &ve, int head, vector<int>& informTime){
        int ss = ve[head].size();
        int ma = 0;
        for(int i = 0; i < ss; i++){
            ma = max(ma, dfs(ve, ve[head][i], informTime));
        }
        return informTime[head] + ma;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int> > ve(n, vector<int> ());

        for(int i = 0; i < n; i++){
            ve[manager[i]].push_back(i);
        }         
        return dfs(ve, headID, informTime);
    }
};

int main(){

    return 0;
}