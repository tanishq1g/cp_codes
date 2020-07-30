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

void preorder(vector<int> &ve, Node * root){
    if(!root)
        return;
    preorder(ve, root->left);
    
    if(root->left == NULL){
        ve.push_back(root->data);
    }
    else if(root->right == NULL){
        ve.push_back(root->data);
    }
    else{
        if(root->left->left == NULL && root->right->right == NULL){
            ve.push_back(root->data);
        }
    }
    preorder(ve, root->right);
}
vector <int> bottomView(Node *root){
    vector<int> ve;

    if(!root)
        return ve;
    preorder(ve, root);
}