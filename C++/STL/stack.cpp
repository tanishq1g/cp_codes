#include <algorithm>
#include <stack>
using namespace std;
// LIFO STACK

void main(){
    stack<int> s;
    s.push(12);
    s.pop();

    // returns top element of the stack
    s.top();

    s.empty();
}