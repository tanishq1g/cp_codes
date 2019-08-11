
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        ListNode * res = NULL, * curr = NULL, * temp = NULL;
        res = curr;
        int car = 0, sum, rem;
        while(l1 != NULL && l2 != NULL){
            // cout<<"val.  "<<l1->val<<' '<<l2->val<<'\n';
            sum = l1-> val + l2->val + car;
            rem = sum%10;
            car = sum/10;
            temp = new ListNode(rem);
            if(res){
                curr->next = temp;
                curr = curr->next;
            }
            else{
                res = temp;
                curr = temp;
            }
            // cout<<res->val<<' '<<sum<< ' '<<curr->val<<'\n';
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == NULL){
            while(l2 != NULL){
                sum = l2->val + car;
                rem = sum%10;
                car = sum/10;
                temp = new ListNode(rem);
                if(res){
                    curr->next = temp;
                    curr = curr->next;
                }
                else{
                    res = temp;
                    curr = temp;
                }
                // cout<<res->val<<' '<<sum<< ' '<<curr->val<<'\n';
                l2 = l2->next;
            }
        }
        else if(l2 == NULL){
            while(l1 != NULL){
                sum = l1->val + car;
                rem = sum%10;
                car = sum/10;
                temp = new ListNode(rem);
                if(res){
                    curr->next = temp;
                    curr = curr->next;
                }
                else{
                    res = temp;
                    curr = temp;
                }
                l1 = l1->next;
            }
        }
        if(car){
            temp = new ListNode(car);
            if(res){
                curr->next = temp;
                curr = curr->next;
            }
            else{
                res = temp;
                curr = temp;
            }
        }
        return res;
    }
};