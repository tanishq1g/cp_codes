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

void preorder(Node * root, int vl, vector<queue<int> > &vqf, vector<queue<int> > &vqb){
    if(!root)
        return;
    if(vl >= 0){
        if(vqf.size() < vl + 1){
            vqf.push_back(queue<int> ());
        }
        vqf[vl].push(root->data);
        cout << "vqf " << vl << ' ' << root->data<<'\n';
    }
    else{
        if(vqb.size() < (-1 * vl)){
            vqb.push_back(queue<int> ());
        }
        vqb[(-1 * vl) - 1].push(root->data);
        cout << "vqb " << vl << ' ' << root->data<<'\n';
    }
    preorder(root->left, vl - 1, vqf, vqb);
    preorder(root->right, vl +  1, vqf, vqb);
}
// root: root node of the tree
vector<int> verticalOrder(Node *root){
    vector<int> ve;
    if(!root)
        return ve;
    vector<queue<int> > vqf, vqb;  
    preorder(root, 0, vqf, vqb);
    int lf = vqf.size(), lb = vqb.size();
    for(int i = lb - 1; i >= 0; i--){
        while(!vqb[i].empty()){
            ve.push_back(vqb[i].front());
            vqb[i].pop();
        }
    }
    for(int i = 0; i < lf; i++){
        while(!vqf[i].empty()){
            ve.push_back(vqf[i].front());
            vqf[i].pop();
        }
    }
    return ve;
}