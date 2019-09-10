#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        
        map<Node*, Node*> m;
        queue<Node*> q;
        Node* ret = new Node(node->val, vector<Node*>());
        q.push(node);
        m[node] = ret;
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for (auto next: curr->neighbors) {
                if (m.find(next) == m.end()) {
                    Node* temp = new Node(next->val, vector<Node*>());
                    m[next] = temp;
                    q.push(next);
                }
                (m[curr]->neighbors).push_back(m[next]);
            }
        }
        return ret;
    }
};