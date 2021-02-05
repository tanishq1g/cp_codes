/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* head) {
    vector<vector<int> > ret;
    if(head == NULL)
        return head;
    queue<TreeNode *> q;
    q.push(head);
    int sq;
    TreeNode * cur;
    while(q.empty() == false){
        sq = q.size();
        vector<int> temp;
        for(int i = 0; i < sq; i++){
            cur = q.top();
            q.pop();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            temp.push_back(cur->val);
        }
        ret.push_back(temp);
    }
    return ret;
}
