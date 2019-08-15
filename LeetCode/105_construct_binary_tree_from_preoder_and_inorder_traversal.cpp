#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// IMPORTANT
class Solution {
    TreeNode * recursion_build(vector<int> &preorder, int preleft, int preright, vector<int> &inorder, int inleft, int inright){
        if(preleft > preright || inleft > inright)
            return NULL;
        int i = 0;
        TreeNode * node = new TreeNode(preorder[preleft]);
        for (i = inleft; i <= inright; i++){
            if(inorder[i] == preorder[preleft])
                break;
        }
        node->left = recursion_build(preorder, preleft + 1, preleft + i - inleft, inorder, inleft, i - 1);
        node->right = recursion_build(preorder, preleft + i - inleft + 1, preright, inorder, i + 1, inright);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int sp = preorder.size(), si = inorder.size();
        TreeNode * root = NULL;
        if(sp == 0 || si == 0)
            return root;
        return recursion_build(preorder, 0, sp - 1, inorder, 0, si - 1);
    }
};