/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
//  linked list
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        // cout << head->val << '\n';
        ListNode * prev = NULL, * cur = head, * next, * n2 = head;
        int i;
        for(i = 0; i < k && cur != NULL; i++){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if(i != k)
            return reverseKGroup(prev, i);
        n2->next = reverseKGroup(cur, k);
        return prev;
    }
};