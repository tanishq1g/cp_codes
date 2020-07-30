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

void deleteNode(Node *node){
   while(node->next->next != NULL){
       node->data = node->next->data;
       node = node->next;
   }
   node->data = node->next->data;
   node->next = NULL;
}