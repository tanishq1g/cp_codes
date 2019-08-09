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
// TWO POINTERS
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        if(slow == NULL)
            return false;
        ListNode * fast = head->next;
        while(slow != fast){
            if(fast == NULL || fast->next == NULL){
                // cout<<"sda";
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};