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
// DFS
class Solution {
    // maxpath signify when root has been included in the maxpath as root node
    int dfs(TreeNode * root, int &maxpath){
        if(!root)
            return 0;
        int l = dfs(root->left, maxpath);
        int r = dfs(root->right, maxpath);
        int pathsingle = max(0, max(l, r) + root->val);
        maxpath = max(maxpath, root->val + l + r);
        return pathsingle;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxpath
        dfs(root, maxpath = INT_MIN);
        return maxpath;
    }
};