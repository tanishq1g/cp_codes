#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
// DFS SOLUTION
    // int maxDepth(TreeNode* root) {
    //     if(!root)
    //         return 0;
    //     return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    // }

// BFS SOLUTION
    int maxDepth(TreeNode * root){
        if(!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int s, depth = 0;
        TreeNode * cur, *l, *r;
        while(!q.empty()){
            s = q.size();
            for (size_t i = 0; i < s; i++){
                cur = q.front(); q.pop();
                l = cur->left;
                r = cur->right;
                if(l)
                    q.push(l);
                if(r)
                    q.push(r);
            }
            depth++;
        }
        return depth;
    }
};
