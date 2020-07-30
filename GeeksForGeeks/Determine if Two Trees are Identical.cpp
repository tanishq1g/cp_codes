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

bool isIdentical(Node *r1, Node *r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 == NULL || r2 == NULL){
        return false;
    }
    return r1->data == r2->data && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}
