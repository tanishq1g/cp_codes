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

/* Removes min element from min heap and returns it */
int MinHeap::extractMin() {
    if(heap_size == 0)
        return -1;
    if(heap_size == 1){
        int x = harr[0];
        heap_size--;
        return harr[0];
    }
    int x = harr[0];
    deleteKey(0);
    return x;
}

/* Removes element from position x in the min heap  */
void MinHeap::deleteKey(int i) {
    if(i >= heap_size)
        return;
    heap_size--;
    if(harr[i] < harr[heap_size]){
        harr[i] = harr[heap_size];
        MinHeapify(i);
    }
    else{
        harr[i] = harr[heap_size];
        decreaseKey(i);
    }
}

/* Inserts an element at position x into the min heap*/
void MinHeap::insertKey(int k) {
    if(heap_size == capacity){
        return;
    }
    heap_size++;
    decreaseKey(heap_size - 1, k);
}

// Decrease Key operation, helps in deleting key from heap
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}