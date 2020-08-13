class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* subtree_s, TreeNode* subtree_l) {
        // make sure subtree_s is smaller than subtree_l
        if (subtree_s->val > subtree_l->val) swap(subtree_s, subtree_l);
        
        while (root->val < subtree_s->val || root->val > subtree_l->val) {
            // if current node is smaller than subtree_s
            // the LCA must be on the right side of the tree
            while (root->val < subtree_s->val) {
                root = root->right;
            }
            
            // if current node is larger than subtree_l
            // the LCA must be on the left side of the tree
            while (root->val > subtree_l->val) {
                root = root->left;
            }
        }
        
        // if the current node value is larger than subtree_s
        // and smaller than subtree_l, it must be the LCA
        return root;
    }
};