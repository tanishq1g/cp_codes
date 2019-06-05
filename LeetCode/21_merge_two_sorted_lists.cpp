#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * p = l1;
        ListNode * q = l2;
        ListNode * head, * r;
        if(!p){
            return l2;
        }
        if(!q){
            return l1;
        }
        if(p->val <= q->val){
            head = p;
            p = p->next;
        }
        else{
            head = q;
            q = q->next;
        }
        r = head;
        while(p || q){
            if(!p){
                r->next = q;
                break;
            }
            if(!q){
                r->next = p;
                break;
            }
            if(p->val <= q->val){
                r->next = p;
                r = r->next;
                p = p->next;
            }
            else if(p->val > q->val){
                r->next = q;
                r = r->next;
                q = q->next;
            }
        }
        return l3;
    }

    ListNode* mergeTwoLists_recursion(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode* t;
        if (l1->val < l2->val)
        {
            t = l1;
            l1 = l1->next;
        }
        else
        {
            t = l2;
            l2 = l2->next;
        }
        
        t->next = mergeTwoLists_recursion(l1, l2);
        return t;
    }
};

void main(){
    Solution sol;
    ListNode * l1;
    ListNode * l2;

}