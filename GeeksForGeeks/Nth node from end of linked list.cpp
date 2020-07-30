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
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// linked list

int getNthFromLast(Node *head, int n){
    int len = 0, i;
    struct Node* temp = head;

    // count the number of nodes in Linked List
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }

    // check if value of n is not
    // more than length of the linked list
    if (len < n){
        return -1;
    }

    temp = head;

    // get the (len-n+1)th node from the beginning
    for (i = 1; i < len - n + 1; i++)
        temp = temp->next;

    return temp->data;

}

int getNthFromLast(Node *head, int n){
    struct Node *main_ptr = head;
    struct Node *ref_ptr = head;

    int count = 0;
    if(head != NULL){
        while( count < n )
        {
            if(ref_ptr == NULL)
            {
            return -1;
            }
            ref_ptr = ref_ptr->next;
            count++;
        } /* End of while*/

        while(ref_ptr != NULL)
        {
            main_ptr = main_ptr->next;
            ref_ptr  = ref_ptr->next;
        }
        return main_ptr->data;
    }
}
