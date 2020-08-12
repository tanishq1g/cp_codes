// trees

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
    int ma;
    int dfs(TreeNode * root, int level){
        if(root == nullptr){
            return level - 1;
        }
        int l = dfs(root->left, level + 1);
        int r = dfs(root->right, level + 1);
        ma = max(ma, l + r - (2 * level));
        cout << root->val << ' ' << l << ' ' << r << ' ' << ma << '\n';
        return max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        ma = INT_MIN;
        return max(ma, dfs(root->left, 1) + dfs(root->right, 1));
    }
};