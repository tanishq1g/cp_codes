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

// Should reverse list and return new head.
struct Node* reverseList(struct Node *head){
    Node * prev, * cur, * next;
    prev = NULL;
    cur = head;
    next = head;
    while(1){
        next = cur->next;
        cur->next = prev;
        if(next == NULL){
            return cur;
        }
        prev = cur;
        cur = next;
    }
    return cur;
}
