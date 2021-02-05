#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <queue>
#include <stack>
using namespace std;

// TREE

void printSpiral(Node *root){
    if(!root)
        return;
    queue<Node *> q;
    q.push(root);
    Node * cur;
    int l = 0;
    while(!q.empty()){
        int sq = q.size();
        vector<int> ve;
        for(int i = 0; i < sq; i++){
            cur = q.front();
            q.pop();
            ve.push_back(cur->data);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        if(l == 1){
            for(int i = 0; i < sq; i++){
                cout << ve[i] << ' ';
            }            
        }
        else{
            for(int i = sq - 1; i >= 0; i--){
                cout << ve[i] << ' ';
            }
        }
        l += 1;
        l %= 2;
        // use flag
    }
}