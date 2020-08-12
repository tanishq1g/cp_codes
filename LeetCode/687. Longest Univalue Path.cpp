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
    int dfs(TreeNode * root){
        if(root == nullptr)
            return 0;
        cout << root->val << '\n';
        if(root->right == nullptr && root->left == nullptr){
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        cout << root->val << ' ' << l << ' ' << r << '\n';
        if(root->left != nullptr &&  root->right != nullptr){
            if(root->val == root->left->val && root->val == root->right->val){
                ma = max(ma, l + r + 2);
                return max(l, r) + 1;
            }
            else if(root->val == root->left->val){
                l++;
                ma = max(ma, l);
                return l;
            }
            else if(root->val == root->right->val){
                r++;
                ma = max(ma, r);
                return r;
            }
            else{
                return 0;
            }
        }
        else if(root->left != nullptr){
            if(root->val == root->left->val){
                l++;
                ma = max(ma, l);
                return l;
            }
            else{
                return 0;
            }
        }
        else if(root->right != nullptr){
            cout << in << '\n';
            if(root->val == root->right->val){
                r++;
                ma = max(ma, r);
                return r;
            }
            else{
                return 0;
            }
        }

        return 0;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr)
            return 0;
        ma = INT_MIN;
        return max(ma, dfs(root));
    }
};