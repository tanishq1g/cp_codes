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

Node* sortedMerge(Node* h1, Node* h2)  {  
    Node * result;
    if(!h1)
        return h2;
    if(!h2)
        return h1;
    if(h1->data < h2->data){
        result = h1;
        result->next = sortedMerge(h1->next, h2);
    }
    else{
        result = h2;
        result->next = sortedMerge(h1, h2->next);
    }
    return result;
}  