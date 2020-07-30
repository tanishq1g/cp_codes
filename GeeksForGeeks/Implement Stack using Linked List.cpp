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


/*
The structure of the node of the stack is
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

// And this is structure of MyStack
class MyStack {
private:
StackNode *top;
public :
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};

/* The method push to push element
   into the stack */
void MyStack ::push(int x) {
    it(top == NULL){
        top = new StackNode(x);
    }
    else{
        StackNode * c = new StackNode(x);
        c->next = top;
        top = c;
    }
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop() {
    if(top == NULL)
        return -1;
    int x = top->data;
    top = top->next;
    return x;
}
