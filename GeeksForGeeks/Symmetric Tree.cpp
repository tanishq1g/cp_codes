#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <queue>
#include <stack>
using namespace std;

// TREE
bool preorder(Node * root1, Node * root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    return root1->data == root2->data && preorder(root1->left, root2->right) && preorder(root1->right, root2->left);
}

// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root){
	if(root == NULL)
        return true;
    return preorder(root->left, root->right);
}