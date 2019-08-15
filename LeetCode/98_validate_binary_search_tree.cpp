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
    // maximise lowerlimit and minimize upperlimit

    bool validateBST(TreeNode * root, long long lowerlimit = LONG_MIN, long long upperlimit = LONG_MAX ){
        if(!root)
            return true;
        long int val = root->val;
        // cout<<"dsfg"<<val<<' '<<lowerlimit<<' '<<upperlimit<<'\n';
        if(val <= lowerlimit || val >= upperlimit){
          cout<<"in\n";
            return false;  
        } 
        if(!validateBST(root->left, lowerlimit , val)) return false;
        if(!validateBST(root->right, val, upperlimit))   return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        
        return validateBST(root);
    }
};