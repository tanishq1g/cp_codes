#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode * head2 = head;
        if(!head)
            return head;
        int sum = 0;
        unordered_map<int, ListNode *> umap;
        umap[0] = NULL;
        while(head){
            sum += head->val;
            if(umap.find(sum) != umap.end()){
                if(umap[sum] == NULL){
                    head2 = head->next;
                }
                else
                    umap[sum]->next = head->next;
            }
            else{
                umap[sum] = head;
            }
            head = head->next;
        }
        return head2;
    }
};