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

void divide(Node * head, Node ** a, Node ** b){
    Node * s = head, * f = head->bottom;
    while(f != NULL){
        // cout << "div " << s->data << ' ' << f->data << '\n';
        f = f->bottom;
        if(f != NULL){
            f = f->bottom;
            s = s->bottom;
        }
    }
    *a = head;
    *b = s->bottom;
    s->bottom = NULL;
}

Node * sortedmerge(Node * a, Node * b){
    Node * result;
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    if(a->data < b->data){
        result = a;
        result->bottom = sortedmerge(a->bottom, b);
    }
    else{
        result = b;
        result->bottom = sortedmerge(a, b->bottom);
    }
    return result;
}

void mergesort(Node ** headref){
    Node * head = *headref;
    if(!head)
        return;
    // cout << head->data << '\n';
    if(!head->bottom)
        return;
    Node *a, *b;
    divide(head, &a, &b);
    // cout << a->data << ' ' << b->data << '\n';
    mergesort(&a);
    mergesort(&b);
    *headref = sortedmerge(a, b);
    // Node * cur = *headref;
    // while(cur != NULL){
    //     cout << cur->data << ' ';
    //     cur = cur->bottom;
    // }
    // cout << "ov\n";
}

Node *flatten(Node *head){
    if(!head)
        return NULL;
    Node * ne = head;
    Node *cur = head;
    while(ne != NULL){
        cur = ne;
        while(cur->bottom != NULL){
            cur = cur->bottom;
        }
        cur->bottom = ne->next;
        ne = ne->next;
    }
    mergesort(&head);
    return head;
}