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

Node * inorder2(Node * root){
    if(!root){
        return NULL;
    }
    cout << root->data << endl;
    Node * l, * r;
    l = inorder2(root->left);
    if(l != NULL){
        while(l->right != NULL){
            l = l->right;
        }
        root->left = l;
        l->right = root;
    }
    else{
        root->left = l;
    }

    r = inorder2(root->right);
    if(r != NULL){
        while(r->left != NULL){
            r = r->right;
        }
        root->right = r;    
        r->left = root;
    }
    else{
        root->right = r;
    }
    return root;
}

Node * bToDLL(Node *root){
    if(!root){
        return NULL;
    }
    Node * in = inorder2(root);
    while(in->left){
        in = in->left;
    }
    return in;
}