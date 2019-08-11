#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
// RECURSIVE LINKED LIST
    // ListNode* reverseList(ListNode* head) {
    //     if(head == NULL|| head->next == NULL){
    //         return head;
    //     }
    //     ListNode * headr = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = NULL;
    //     return headr;
    // }

// ITERATIVE LINKED LIST
    ListNode * reverseList(ListNode * head) {
        ListNode * prev = NULL;
        ListNode * curr = head, * nextTemp;
        while (curr != NULL) {
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};