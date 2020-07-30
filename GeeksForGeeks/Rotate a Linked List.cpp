#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// linked list

Node* rotate(Node* head, int k){
    Node * cur = head, * next = head;
    for(int i = 0; i < k; i++){
        if(next == NULL)
            return NULL;
        next = next->next;
    }
    while(next->next != NULL){
        cur = cur->next;
        next = next->next;
    }
    Node * head2 = cur->next;
    cur->next = NULL;
    next->next = head;
    return head2;
}

Node* rotate(Node* head, int k){
    Node* temp = head;
while(temp->next){
temp = temp->next;
}
temp->next = head; // linking last node with first node
Node *end;
while(k--){
end = head;
head = head->next;
}
// end is previous of updated head, so make end of next as null as it is the last node of updated linked list
end->next = NULL;
return head;
}