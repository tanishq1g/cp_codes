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

int height(Node * root, int h, int &ph){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
        return h;
    int l = height(root->left, h + 1, ph); 
    int r = height(root->right, h + 1, ph); 
    ph = max(ph, l + r - h - h + 1);
    return max(l, r);
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    if(node == NULL)
        return 0;
    int ph = INT_MIN;
    return max(height(node->left, 1, ph) + height(node->right, 1, ph) + 1, ph);
}
