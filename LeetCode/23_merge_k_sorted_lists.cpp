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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * re = NULL, * minnode = NULL, * curr = NULL;
        int slists = lists.size(), count = slists, minele = INT_MAX, minind;
        vector<bool> ch(slists, false);
        while(count>0){
            cout<<"count "<<count<<'\n';
            minele = INT_MAX;
            for (int i = 0; i < slists; i++){
                cout<<"i "<<i<<" ch[i] "<<ch[i];
                if(ch[i]){
                    cout<<" if0\n";
                    continue;
                }
                if(!lists[i]){
                    cout<<" in if1 \n";
                    count--;
                }
                else{
                    cout<<" inelse1 \n";
                    if(lists[i]->val < minele){
                        minele = lists[i]->val;
                        minind = i;
                        cout<<" minfound "<<minele<<' '<<minind<<'\n';
                    }
                }
            }
            minnode = new ListNode(minele);
            // if(!ch[minind]){
                if(lists[minind]->next == NULL){
                    cout<<" in ifif2 \n";
                    count--;
                    ch[minind] = true;
                }
            // }
            if(!re){
                cout<<"    newnode ";
                re = minnode;
                curr = re;
                cout<<re->val<<'\n';
            }
            else{
                curr->next = minnode;
                curr = minnode;
                cout<<"    add node"<<curr->val<<' '<<re->val<<'\n';
            }
            lists[minind] = lists[minind]->next;
        }
        return re;
    }
};

int main(){
    Solution sol;
    vector<string> re;
    re = sol.generateParenthesis(6);
    for (size_t i = 0; i < re.size(); i++)
    {
        cout<<re[i]<<'\n';
    }
    
    return 0;
}