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


/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

/* The method push to push element into the queue*/
void MyQueue:: push(int x){
    if(front == NULL){
        front = rear = new QueueNode(x);
        return; 
    }
    QueueNode * c = new QueueNode(x);
    c->next = rear;
    rear = c;
}
/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop(){
    if(front == NULL)
        return -1;
    int re = front->data;
    front = front->next;
    return re;       
}
