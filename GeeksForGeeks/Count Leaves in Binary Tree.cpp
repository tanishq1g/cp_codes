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
int countLeaves(Node* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    for (int i = 0; i < n; i++) {
        <#statements#>
    }
    
    return countLeaves(root->left) + countLeaves(root->right);
}
