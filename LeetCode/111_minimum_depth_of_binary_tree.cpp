#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

// BFS
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode * temp;
        int dep = 1;
        int sq;
        while(!q.empty()){
            sq = q.size();
            for(int i = 0; i < sq; i++){
                temp = q.front(); q.pop();
                if(temp->left == NULL && temp->right == NULL){
                    return dep;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            dep++;
        }
        return dep;
    }
};