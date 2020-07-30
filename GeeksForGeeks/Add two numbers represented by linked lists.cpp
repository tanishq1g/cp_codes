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
    if(head == NULL)
        return head;
    Node * prev, * cur, * next;
    prev = NULL;
    cur = head;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second){
    if(!first)
        return second;
    if(!second)
        return first;
    first = reverse(first);
    second = reverse(second);
    // Node * cur = first;
    // while(cur != NULL){
    //     cout << cur->data << ' ';
    //     cur = cur->next;
    // }cout << '\n';
    // cur = second;
    // while(cur != NULL){
    //     cout << cur->data << ' ';
    //     cur = cur->next;
    // }cout << '\n';
    
    Node * ret = NULL, *end, *lo;
    int su, ca = 0;
    while(first != NULL && second != NULL){
        su = ca + first->data + second->data;
        if(su >= 10){
            su = su - 10;
            ca = 1;
        }
        else{
            ca = 0;
        }
        if(ret == NULL){
            ret = new Node(su);
            end = ret;
        }
        else{
            lo = new Node(su);
            end->next = lo;
            end = end->next;
        }
        first = first->next;
        second = second->next;
    }
    
    // if(first != NULL){
        while(first != NULL){
            su = ca + first->data;
            if(su >= 10){
                su = su - 10;
                ca = 1;
            }
            else{
                ca = 0;
            }
            if(ret == NULL){
                ret = new Node(su);
                end = ret;
            }
            else{
                lo = new Node(su);
                end->next = lo;
                end = end->next;
            }
            first = first->next;
        }
    // }
    // if(second != NULL){
        while(second != NULL){
            su = ca + second->data;
            if(su >= 10){
                su = su - 10;
                ca = 1;
            }
            else{
                ca = 0;
            }
            if(ret == NULL){
                ret = new Node(su);
                end = ret;
            }
            else{
                lo = new Node(su);
                end->next = lo;
                end = end->next;
            }
            second = second->next;
        }
    if(ca == 1){
        lo = new Node(ca);
        end->next = lo;
        end = end->next;
    }
    // }
    return reverse(ret);
}