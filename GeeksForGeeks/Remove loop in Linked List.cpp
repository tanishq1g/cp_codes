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

void removeLoop(Node* head){
    Node * p1 = head, * p2 = head;
    while(1){
        if(!p1 || !p2)
            return;
        p1 = p1->next;
        p2 = p2->next;
        if(!p2)
            return;
        p2 = p2->next;
        if(p1 == p2){
            break;
        }
    }
    Node * loopnode = p2;
    if(loopnode == head){
        while(p2->next != head){
            p2 = p2->next;
        }
        p2->next = NULL;
        return;
    }
    // p1 = head;
    // if(p1 == loopnode->next){
    //     loopnode->next = NULL;
    //     return;
    // }
    // while(1){
    //     while(p2->next != p1 && p2 != loopnode){
    //         p2 = p2->next;
    //     }
    //     if(p1 == p2->next){
    //         loopnode->next = NULL;
    //         return;
    //     }
    //     p1 = p1->next;
    // }
    struct Node* ptr1 = loopnode;
    struct Node* ptr2 = loopnode;

    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }

    // Fix one pointer to head
    ptr1 = head;

    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;

    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;

    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
}