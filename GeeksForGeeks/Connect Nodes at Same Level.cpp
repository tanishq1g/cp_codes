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

void connect(Node *p){
    if(!p)
        return;
    
    queue<Node *> q;
    Node * cur, * cur1;
    int sq = q.size();
    while(sq != 0){
        for(int i = 0; i < sq; i++){
            cur = q.front();
            q.pop();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            if(i + 1 > sq - 1)
                cur->nextRight = NULL;
            else{
                cur1 = q.front();
                cur->nextRight = cur1;
            }
        }
        sq = q.size();
    }
}