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

int intersectPoint(Node* head1, Node* head2){
    Node * cur, *cur2;
    int c1 = 0, c2 = 0;
    cur = head1;
    while(cur){
        cur = cur->next;
        c1++;
    }
    cur = head2;
    while(cur){
        cur = cur->next;
        c2++;
    }
    cur = head1;
    cur2 = head2;
    int k = abs(c1 - c2);
    if(c1 >= c2){
        while(k--){
            cur = cur->next;
        }
    }
    else{
        while(k--){
            cur2 = cur2->next;
        }
    }
    while(1){
        if(cur == cur2){
            return cur->data;
        }
        cur = cur->next;
        cur2 = cur2->next;
    }
    return -1;
}