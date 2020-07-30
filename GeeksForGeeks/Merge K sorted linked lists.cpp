#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <climits>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// HEAPS

// struct Node
// {
// 	int data;
// 	Node* next;
	
// 	Node(int x){
// 	    data = x;
// 	    next = NULL;
// 	}
	
// };

struct cmp{
    bool operator()(pair<int, Node *> &p1, pair<int, Node *> &p2){
        if(p1.first > p2.first)
            return true;
        return false;
    }
};
/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node * mergeKLists(Node *arr[], int n){
    int en = 0;
    priority_queue<pair<int, Node *>, vector<pair<int, Node *> >, cmp> pq;
    for(int i = 0; i < n; i++){
        if(arr[i] != NULL){
            pq.push(make_pair(arr[i]->data, arr[i]));
        }
        else{
            en++;
        }
    }
    Node * head, * end, * cur;
    cur = pq.top().second;
    pq.pop();
    head = cur;
    end = cur;
    if(cur->next != NULL){
        pq.push(make_pair(cur->next->data, cur->next));
    }
    else{
        en++;
    }
    while(en < n){
        cur = pq.top().second;
        end->next = cur;
        end = cur;
        pq.pop();
        if(cur->next != NULL){
            pq.push(make_pair(cur->next->data, cur->next));
        }
        else{
            en++;
        }
    }
    while(!pq.empty()){
        cur = pq.top().second;
        end->next = cur;
        end = cur;
        pq.pop();
    }
    return head;
}