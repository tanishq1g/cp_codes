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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);
        TreeNode * lt, * rt;
        while(!q.empty()){
            lt = q.front(); q.pop();
            rt = q.front(); q.pop();
            if(lt == NULL && rt == NULL) continue;
            if(lt == NULL || rt == NULL) return false;
            if(lt->val != rt->val) return false;
            q.push(lt->left);
            q.push(rt->right);
            q.push(lt->right);
            q.push(rt->left);
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<int> vec{1,2,2,3,4,4,5};
    TreeNode * root = new TreeNode(1);
    root->left = NULL;
    root->right = new TreeNode(2);
    cout<<sol.isSymmetric(root);
    return 0;
}