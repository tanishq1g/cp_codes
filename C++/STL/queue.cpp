#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
// FIFO QUEUE

int main(){
    queue<int> q;
    // Inserts a new element at the end of the queue
    q.push(12);
    // returns the oldest element in the queue
    cout << q.front();
    // The element removed is the "oldest" element in the queue whose value can be retrieved by calling member queue::front. returns void
    q.pop();

    // returns size
    q.size()
    return 0;
}