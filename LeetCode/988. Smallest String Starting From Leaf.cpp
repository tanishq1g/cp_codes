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
public:
    string smallestFromLeaf(TreeNode* root) {
        string result = "";
        
        queue<pair<TreeNode*, string>> bfs;
        string root_string = "";
        root_string = char(root->val + 97) + root_string;
        
        bfs.push({root, root_string});
        pair<TreeNode*, string> curr;
        
        while(!bfs.empty()){
            curr = bfs.front();
            bfs.pop();
            
            if(curr.first->left == NULL && curr.first->right == NULL){
                if(result == "") result = curr.second;
                else result = (curr.second < result) ? curr.second : result;
            }
            
            if(curr.first->left){
                root_string = char(curr.first->left->val + 97) + curr.second;
                bfs.push({curr.first->left, root_string});
            }
            if(curr.first->right){
                root_string = char(curr.first->right->val + 97) + curr.second;
                bfs.push({curr.first->right, root_string});
            }
        }
        
        return result;
    }
};