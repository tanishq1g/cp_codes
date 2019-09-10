#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

// BFS
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        int i;
        while(!q.empty()) {
            vector<int> curLevel;
            int b = q.size();
            for( i = 0; i < b; i++) {
                TreeNode* cur = q.front();
                q.pop();
                curLevel.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(curLevel);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};