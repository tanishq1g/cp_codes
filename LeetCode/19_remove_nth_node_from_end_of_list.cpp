#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// TWO POINTERS
// LINKED LIST
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		assert(n>0);
		ListNode* dummyHead=new ListNode(0);
		dummyHead->next=head;

		ListNode* p=dummyHead;
		ListNode* q=p;
		for(int i=0;i<n+1;++i){
			assert(q);
			q=q->next;
		}

		while(q!=NULL){
			p=p->next;
			q=q->next;
		}

		ListNode* delNode=p->next;
		p->next=delNode->next;
		delete delNode;
		ListNode* retNode=dummyHead->next;
		delete dummyHead;
		return retNode;
	}
};