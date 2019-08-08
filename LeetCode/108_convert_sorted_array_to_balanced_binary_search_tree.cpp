#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>

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
    TreeNode * insert(vector<int>& nums, int l, int r){
        if(l > r){
            // cout<<"retun\n";
            return NULL;
        }
        TreeNode * root;
        int m = (l + r + 1) / 2;
        root = new TreeNode(nums[m]);
        // cout<<"asd"<<l<<' '<<m<<' '<<r<<' '<<root->val<<'\n';
        root -> left = insert(nums, l, m-1);
        root -> right = insert(nums, m+1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * root = NULL;
        if(nums.size() == 0){
            return root;
        }
        return insert(nums, 0, nums.size() - 1);
        // return root;
    }

    // void insert(vector<int>& nums, int l, int r, TreeNode *& root){
    //     if(l > r){
    //         cout<<"retun\n";
    //         return;
    //     }
    //     int m = (l + r + 1) / 2;
    //     root = new TreeNode(nums[m]);
    //     cout<<"asd"<<l<<' '<<m<<' '<<r<<' '<<root->val<<'\n';
    //     insert(nums, l, m-1, root->left);
    //     insert(nums, m+1, r, root->right);
    // }
    // TreeNode* sortedArrayToBST(vector<int>& nums) {
    //     TreeNode * root = NULL;
    //     if(nums.size() == 0){
    //         return root
    //     }
    //     insert(nums, 0, nums.size() - 1, root);
    //     return root;
    // }
};

int main(){
    vector<int> nums{-10,-3,0,5,9};
    Solution sol;
    TreeNode * root = sol.sortedArrayToBST(nums);
    cout<<root->val;
    return 0;
}