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

void serialize(Node *root,vector<int> &A){
    if(root == NULL)
        return;
    serialize(root->left, A);
    A.push_back(root->data);
    serialize(root->right, A);
}

Node * deSerialize(vector<int> &A){
   
}