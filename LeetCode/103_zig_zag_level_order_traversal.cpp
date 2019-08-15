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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > re;
        if(!root) return re;
        queue<stackst> st;
        stackst temp = stackst(NULL, -1);
        int curd= 0;
        vector<int> ve;
        bool l2r = true;
        st.push(stackst(root, 0));
        while(!st.empty()){
            temp = st.front(); st.pop();
            // cout<<temp.node->val<<'\n';
            if(temp.node->left)
                st.push(stackst(temp.node->left, temp.depth + 1));
            if(temp.node->right)
                st.push(stackst(temp.node->right, temp.depth + 1));
            if(temp.depth != curd){
                if(l2r){
                    re.push_back(ve);
                    l2r = false;
                }
                else{
                    reverse(ve.begin(), ve.end());
                    re.push_back(ve);
                    l2r = true;
                }
                curd++;
                ve = {};
            }
            ve.push_back(temp.node->val);
            // cout<<ve.size()<<"ASdf\n";
        }
        if(l2r){
            re.push_back(ve);
            l2r = false;
        }
        else{
            reverse(ve.begin(), ve.end());
            re.push_back(ve);
            l2r = true;
        }
        return re;
    }

// WITHOUT STACKST
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        auto level = 0;
        
        if (!root)
            return res;
        
        q.push(root);
        
        while (not q.empty()) {
            auto size = q.size();
            vector<int> v;

            for (auto i = 0; i < size; i++) {
                TreeNode *t = q.front();
                
                q.pop();
                v.push_back(t->val);
                
                if (t->left)
                    q.push(t->left);
                
                if (t->right)
                    q.push(t->right);
            }

            if (level % 2 == 1)
                reverse(v.begin(), v.end());
                
            res.push_back(v);
            level++;
        }
        return res;
    }
};
