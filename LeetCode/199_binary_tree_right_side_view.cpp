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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> re;
        if(!root)
            return re;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode * temp;
        int sq = q.size();
        while(!q.empty()){
            sq = q.size();
            for(int i = 0; i < sq; i++){
                temp = q.front(); q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            re.push_back(temp->val);
        }
        return re;
    }
};