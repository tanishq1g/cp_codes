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

class Solution {
    struct stackst{
        TreeNode * node;
        int depth;
        stackst(TreeNode * n, int d): node(n), depth(d){}
    };
public:
// level order traversal using queue
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > re;
        if(!root) return re;
        queue<stackst> st;
        stackst temp = stackst(NULL, -1);
        int curd= 0;
        vector<int> ve;
        st.push(stackst(root, 0));
        while(!st.empty()){
            temp = st.front(); st.pop();
            // cout<<temp.node->val<<'\n';
            if(temp.node->left)
                st.push(stackst(temp.node->left, temp.depth + 1));
            if(temp.node->right)
                st.push(stackst(temp.node->right, temp.depth + 1));
            if(temp.depth != curd){
                re.push_back(ve);
                curd++;
                ve = {};
            }
            ve.push_back(temp.node->val);
            // cout<<ve.size()<<"ASdf\n";
        }
        re.push_back(ve);
        return re;
    }

// BFS
vector<vector<int>> levelOrder(TreeNode* root) {
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
        return res;
    }
};