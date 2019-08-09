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
// two pointer technique
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;
        ListNode *curA = headA, *curB = headB;
        while(curA && curB && curA != curB){
            curA = curA->next;
            curB = curB->next;
            if(!curA && !curB)
                return nullptr;
            if(!curA)
                curA = headB;
            if(!curB)
                curB = headA;
        }
        return curA;
    }
};

int main(){
    int * p;
    *p =2;
    cout<<p<<' '<<&p<<' '<<*p;
    return 0;
}