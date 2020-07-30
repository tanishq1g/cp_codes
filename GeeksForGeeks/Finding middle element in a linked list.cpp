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

/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head){
    Node *cur;
    cur = head;
    int c = 0;
    while(cur != NULL){
        c++;
        cur = cur->next;
    }
    cout << c << '\n';
    if(c % 2 == 0){
        c = c / 2;
        cur = head;
        for(int i = 0; i < c; i++){
            cur = cur->next;
        }
        return cur->data;
    }
    else{
        c = c / 2;
        c++;
        cur = head;
        for(int i = 0; i < c; i++){
            cur = cur->next;
        }
        return cur->data;
    }

    // 2 pointer approach
    
    // struct Node *slow_ptr = head; 
    // struct Node *fast_ptr = head; 

    // if (head!=NULL) 
    // { 
    //     while (fast_ptr != NULL && fast_ptr->next != NULL) 
    //     { 
    //         fast_ptr = fast_ptr->next->next; 
    //         slow_ptr = slow_ptr->next; 
    //     } 
    //     printf("The middle element is [%d]\n\n", slow_ptr->data); 
    // } 
}