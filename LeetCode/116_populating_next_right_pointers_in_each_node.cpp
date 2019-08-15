#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> q;
        if(!root)
            return NULL;
        int sq = 1;
        q.push(root);
        Node * temp = NULL;
        while(!q.empty()){
            sq = q.size();
            while(sq > 0){
                // cout<<"sq"<<sq<<'\n';
                if(temp){
                    temp->next = q.front();
                    temp = temp->next;
                } 
                else
                    temp = q.front();
                // cout<<temp->val<<'\n';
                q.pop();
                if(!temp)
                    break;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                sq--;
            }
            temp->next = NULL;
            temp = NULL;
        }
        return root;
    }
};