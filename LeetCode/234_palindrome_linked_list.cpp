#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * reverseLinkedList(ListNode * head){
        ListNode * prev = NULL, * curr = head, * nexttemp;
        while(curr != NULL){
            nexttemp = head->next;
            curr->next = prev;
            prev == curr;
            curr = curr->next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        int s = 0, m;
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode * temp = head;
        while(temp->next != NULL){
            s++;
            temp = temp->next;
        }
        s++;
        if(s%2 == 0)
            m = s/2;
        else
            m = (s/2) + 1;
        temp = head;
        for (int i = 0; i <= m; i++)
        {
            temp = temp->next;
        }
        ListNode * headr = reverseLinkedList(temp);
        if(s%2 == 0){
            for (int i = 0; i < m; i++)
            {
                if(head->val != headr->val)
                    return false;
                head = head->next;
                headr = headr->next;
            }
        }
        else{
            for (int i = 0; i < m - 1; i++)
            {
                if(head->val != headr->val)
                    return false;
                head = head->next;
                headr = headr->next;
            }
        }
        return true;
    }
};