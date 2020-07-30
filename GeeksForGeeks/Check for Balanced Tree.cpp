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
int height(Node * root, int h, bool &ch){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return h;
    if(root->left == NULL){
        int r = height(root->right, h + 1, ch);
        if(r - h > 1)
            ch = false;
        return r;
    }
    if(root->right == NULL){
        int l = height(root->left, h + 1, ch);
        if(l - h > 1)
            ch = false;
        return l;
    }
    int l = height(root->left, h + 1, ch);
    int r = height(root->right, h + 1, ch);
    cout << root->data << ' ' << l << ' ' << r << ' ' << ch<<endl;
    if(abs(r - l) > 1){
        ch = false;
    }
    return max(l, r);

}
bool isBalanced(Node *root){
    if(root == NULL)
        return true;
    bool ch = true;
    int x = height(root, 0, ch);
    return ch;
}