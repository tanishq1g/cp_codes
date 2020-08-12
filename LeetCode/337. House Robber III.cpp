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

//  dynamic programming tree

class Solution {
    pair<int, int> dfsdp(TreeNode * root){
        if(root == nullptr)
            return make_pair(0, 0);
        pair<int, int> l, r, c = make_pair(0, 0);
        l = dfsdp(root->left);
        r = dfsdp(root->right);
        c.first = root->val + l.second + r.second;
        c.second = max(l.first + r.first, max(l.first + r.second, max(l.second + r.first, l.second + r.second)));
        return c;
    }
public:
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;
        pair<int, int> r = dfsdp(root);
        return max(r.first, r.second);
    }
};