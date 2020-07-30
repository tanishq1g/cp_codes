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

int height(Node* root){
    if(!root)
        return 0;
    int l = 0;
    queue<Node*> q;
    Node * cur;
    q.push(root);
    int sq = q.size();
    while(sq != 0){
        for(int i = 0; i < sq; i++){
            cur = q.front();q.pop();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        l++;
        sq = q.size();
    }
    return l;
}