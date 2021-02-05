/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode * insertbalancedBST(int l, int r, vector<int> &ve){
    if(l > r){
        return NULL;
    }
    int m = (l + r) / 2;
    TreeNode * root;
    root = new TreeNode(ve[m]);
    root->left = insertbalancedBST(l, m - 1, ve);
    root->right = insertbalancedBST(m + 1, r, ve);
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* lihead) {
    if(lihead == NULL)
        return NULL;
    vector<int> ve;
    ListNode * cur = lihead;
    while(cur != NULL){
        ve.push_back(cur->val);
        cur = cur->next;
    }
    return insertbalancedBST(0, ve.size() - 1, ve);
}




// int getSize(ListNode* A){
//     int len=0;
//     while(A!=NULL){
//         A=A->next;
//         len++;
//     }
//     return len;
// }
// ListNode* get(ListNode* A,int idx){
//     for(int i=0; i<idx; i++) A=A->next;
//     return A;
// }
// TreeNode* Solution::sortedListToBST(ListNode* A) {
//     if(A==NULL) return NULL;
//     if(A->next==NULL) return (new TreeNode(A->val));
    
//     int n=getSize(A);
//     ListNode *temp=get(A, n/2 - 1);
//     ListNode *right=temp->next;
//     temp->next = NULL;
    
//     TreeNode *root=new TreeNode(right->val);
//     root->left=sortedListToBST(A);
//     root->right=sortedListToBST(right->next);
//     return root;
// }