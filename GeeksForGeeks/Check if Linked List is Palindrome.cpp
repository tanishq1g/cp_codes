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

Node * reverse(Node * head){
    Node * prev = NULL, * cur, * cur2;
    cur = head;
    while(cur != NULL){
        cur2 = new Node(cur->data);
        cur2->next = prev;
        prev = cur2;
        cur = cur->next;
    }
    return prev;
}
bool isPalindrome(Node *head){
    if(head == NULL)
        return false;
    Node * re = reverse(head);
    while(re != NULL && head != NULL){
        if(re->data != head->data)
            return false;
        re = re->next;
        head = head->next;
    }
    return true;
}