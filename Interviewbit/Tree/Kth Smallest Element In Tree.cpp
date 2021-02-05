// /**
//  * Definition for binary tree
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// int Solution::kthsmallest(TreeNode* A, int B) {
//     if(!A)
//         return 0;
//     static int ct = 0;
//     int j;
//     j = kthsmallest(A->left, B);
//     ct++;
//     if(ct == B)
//         return A->val;
//     j = kthsmallest(A->right, B);
//     return j;
// }


**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* A,int &B,int &res){
    if(A==NULL)
    return;
    inorder(A->left,B,res);
    B--;
      if(B==0)
      res=A->val;
     inorder(A->right,B,res);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    int res;
     inorder(A,B,res);
    return res;
}
