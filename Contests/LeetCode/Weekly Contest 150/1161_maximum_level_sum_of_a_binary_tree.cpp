
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
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode * curr;
        int qs;
        int curlevel = 0;
        int maxlevel = 0;
        int maxsum = INT_MIN, cursum;
        while(!q.empty()){
            qs = q.size();
            cursum = 0;
            curlevel++;
            for(int i = 0; i < qs; i++){
                curr = q.front();
                q.pop();
                cursum += curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(cursum > maxsum){
                maxsum = cursum;
                maxlevel = curlevel;
            }
        }
        return maxlevel;
    }
};