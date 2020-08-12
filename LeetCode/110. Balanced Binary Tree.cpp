// tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool t;
    int height(TreeNode * root){
        if(root == nullptr){
            return 0;
        }
        int x = height(root->left) + 1;
        int y = height(root->right) + 1;
        if(abs(x - y) > 1){
            t = true;
        }
        return max(x, y);
    }
public:
    bool isBalanced(TreeNode* root) {
        t = true;
        height(root);
        return t;
    }
};