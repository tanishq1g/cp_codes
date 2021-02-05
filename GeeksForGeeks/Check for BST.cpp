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
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
bool validateBST(Node * root, long long lowerlimit = LONG_MIN, long long upperlimit = LONG_MAX ){
    if(!root)
        return true;
    long int val = root->val;
    // cout<<"dsfg"<<val<<' '<<lowerlimit<<' '<<upperlimit<<'\n';
    if(val <= lowerlimit || val >= upperlimit){
        // cout<<"in\n";
        return false;  
    } 
    if(!validateBST(root->left, lowerlimit , val)) return false;
    if(!validateBST(root->right, val, upperlimit))   return false;
    return true;
}



bool isBST(Node* root) {
    
    return validateBST(root);
}
