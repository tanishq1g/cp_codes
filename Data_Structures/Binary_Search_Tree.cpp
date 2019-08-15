#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

// For a binary tree to be a binary search tree, the data of all the nodes in the left sub-tree of the root node should be ≤ the data of the root. The data of all the nodes in the right subtree of the root node should be  > the data of the root.

// TRAVERSALS

void perorder(struct node*root)
    {
        if(root)
        {
            printf("%d ",root->data);    //Printf root->data
            preorder(root->left);    //Go to left subtree
            preorder(root->right);     //Go to right subtree
        }
    }

void postorder(struct node*root)
    {
        if(root)
        {
            postorder(root->left);    //Go to left sub tree
            postorder(root->right);     //Go to right sub tree
            printf("%d ",root->data);    //Printf root->data
        }
    }

void inorder(struct node*root)
    {
        if(root)
        {
            inorder(root->left);    //Go to left subtree
            printf("%d ",root->data);    //Printf root->data
            inorder(root->right);     //Go to right subtree
        }
    }

void inorder(struct node * root){
    stack<node*> st;
    node * cur;
    while(cur || !st.empty()){
        if(cur){
            st.push(cur);
            cur = cur->left;
        }
        else{
            cur = st.top();
            st.pop();
            out<<cur->val;
            cur = cur->right;
        }
    }
}

// MORRIS TRAVEL
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;
        while(cur) {
            if(!cur->left) {
                ans.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* pred = cur->left;
                while(pred->right && pred->right != cur) pred = pred->right;
                if(!pred->right) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    pred->right = nullptr;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }


        

// INSERTION IN BST

// Compare data of the root node and element to be inserted.

// 1) If the data of the root node is greater, and if a left subtree exists, then repeat step 1 with root = root of left subtree. Else, insert element as left child of current root.
// 2) If the data of the root node is greater, and if a right subtree exists, then repeat step 2 with root = root of right subtree. Else, insert element as right child of current root.

struct node* insert(struct node* root, int data)
    {
        if (root == NULL)    //If the tree is empty, return a new,single node
            return newNode(data);
        else
        {
            //Otherwise, recur down the tree
            if (data <= root->data)
                root->left  = insert(root->left, data);
            else
                root->right = insert(root->right, data);
            //return the (unchanged) root pointer
            return root;
        }
    }

