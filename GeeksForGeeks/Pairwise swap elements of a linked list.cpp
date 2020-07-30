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

Node* pairWiseSwap(struct Node* head) {
    if(!head)
        return head;
    if(!head->next)
        return head;
    Node * cur, *tmp;
    cur = head->next;
    tmp = cur->next;
    cur->next = head;
    cur->next->next = pairWiseSwap(tmp);
    return cur;
}