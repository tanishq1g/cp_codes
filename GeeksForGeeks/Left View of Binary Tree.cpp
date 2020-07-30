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

// A wrapper over leftViewUtil()
void leftView(Node *root){
   // Your code here
    if(root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    int s = q.size();
    Node* temp = NULL;
    while(q.size() != 0){
        for(int i = 0; i < s; i++){
            temp = q.front();q.pop();
            if(i == 0){
                cout << temp->data << ' ';
            }
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
        s = q.size();
    }
}

