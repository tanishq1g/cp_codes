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

bool detectLoop(Node* head){
    Node * p1 = head, * p2 = head;
    if(p1 == NULL || p2 == NULL)
            return false;
    while(1){
        p1 = p1->next;
        p2 = p2->next;
        if(p1 == NULL || p2 == NULL)
            return false;
        p2 = p2->next;
        if(p1 == p2)
            return true;
    }
    return false;
}
