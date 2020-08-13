/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * p, *q, *lca;
    bool dfs(TreeNode* root){
        if(root == NULL)
            return false;
        bool l = dfs(root->left);
        bool r = dfs(root->right);
        if(l && r == true){
            lca = root;
        }
        else if((l || r) && ((root == p) || (root == q))){
            lca = root;
        }
        return l || r || (root == p) || (root == q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* pp, TreeNode* qq) {
        p = pp;
        q = qq;
        lca = NULL;
        bool a = dfs(root);
        if(a){
            return lca;
        }
        else{
            return NULL;
        }
    }
};