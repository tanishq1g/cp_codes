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
    string dfs(TreeNode * root){
        if(root == nullptr)
            return "";
        string l = dfs(root->left);
        string r = dfs(root->right);
        if(l == "" && r == "")
            return l += (root->val + 'a');
        else if(l == ""){
            return r += (root->val + 'a');
        }
        else if(r == ""){
            return l += (root->val + 'a');
        }
        
        l += (root->val + 'a');
        r += (root->val + 'a');

        if(lexicographical_compare(l.begin(), l.end(), r.begin(), r.end())){
            return l;
        }
        else{
            return r;
        }
        
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if(root == nullptr)
            return "";
        return dfs(root);
    }
};