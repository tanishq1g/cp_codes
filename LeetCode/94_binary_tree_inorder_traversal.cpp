#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
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
    vector<int> re;

    // INORDER TRAVERSAL RECURSION
    void inorder_traversal(TreeNode * root){
        if(root){
            inorder_traversal(root->left);
            cout<<root->val<<'\n';
            re.push_back(root->val);
            inorder_traversal(root->right);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder_traversal(root);
        return re;
    }

    
};

