#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>

using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > pa(numRows);
        for (size_t i = 0; i < numRows; i++){
            pa[i] = vector<int>(i+1, 1);
            for (size_t j = 1; j < i; j++){
                pa[i][j] = pa[i-1][j-1] + pa[i-1][j];
            }
            for (vector<int>::iterator it = pa[i].begin(); it != pa[i].end(); ++it)
                cout << ' ' << *it;
            cout << '\n';
        }
        return pa;
    }
};

int main(){
    Solution sol;
    sol.generate(15);
    return 0;
}