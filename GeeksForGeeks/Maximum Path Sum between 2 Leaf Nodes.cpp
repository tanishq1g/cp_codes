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

int postorder(Node * root, int &pmax){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    else if(root->left == NULL){
        int r = postorder(root->right, pmax);
        return r + root->data;
    }
    else if(root->right == NULL){
        int l = postorder(root->left, pmax);
        return l + root->data;
    }
    int l = postorder(root->left, pmax);
    int r = postorder(root->right, pmax);
    pmax = max(pmax, l + r + root->data);
    return max(l, r) + root->data;
}

int maxPathSum(Node* root){ 
    if(root == NULL)
        return 0;
    int pmax = INT_MIN;
    int l = postorder(root->left, pmax);
    int r = postorder(root->right, pmax);
    return max(pmax, l + r + root->data);
}