#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

// A heap is a tree-based data structure in which all the nodes of the tree are in a specific order.

// if parent of y = x, then the value of x follows a specific order to the value of y and the same order will be followed across the tree

// Max Heap: In this type of heap, the value of parent node will always be greater than or equal to the value of child node across the tree and the node with highest value will be the root node of the tree.

// heapify = make the array satisfy the conditions of the heap

// heapify a particular node in the heap
// O(logn)
void max_heapify (int Arr[ ], int i, int N)
{
    int left = 2*i                   //left child
    int right = 2*i +1           //right child
    if(left<= N and Arr[left] > Arr[i] )
            largest = left;
    else
            largest = i;
    if(right <= N and Arr[right] > Arr[largest] )
        largest = right;
    if(largest != i )
    {
        swap (Arr[i] , Arr[largest]);
        max_heapify (Arr, largest,N);
    }
}

// heapifying every value from the second last level in the heap
// O(n) : amortized cost
void build_maxheap (int Arr[ ])
{
    for(int i = N/2 ; i >= 1 ; i-- ) //starting from the second last level
    {
        max_heapify (Arr, i) ;
    }
}



// Min Heap: In this type of heap, the value of parent node will always be less than or equal to the value of child node across the tree and the node with lowest value will be the root node of tree.


void min_heapify (int Arr[ ] , int i, int N)
{
    int left  = 2*i;
    int right = 2*i+1;
    int smallest;
    if(left <= N and Arr[left] < Arr[ i ] )
            smallest = left;
    else
        smallest = i;
    if(right <= N and Arr[right] < Arr[smallest] )
        smallest = right;
    if(smallest != i)
    {
        swap (Arr[ i ], Arr[ smallest ]);
        min_heapify (Arr, smallest,N);
    }
}

void build_minheap (int Arr[ ])
{
    for( int i = N/2 ; i >= 1 ; i--)
    min_heapify (Arr, i);
}

// HEAP SORT
// 1) build a max heap O(n)
// 2) excahnge the largest element that is root with the last element of the array and build max heap again excluding the last element O(logn) is applied n-1 times
// 3) repeat step 2 until all elements are in the correct position

// O(nlogn)
void heap_sort(int Arr[ ])
{
    int heap_size = N;
    build_maxheap(Arr);
    for(int i = N; i>=2 ; i-- )
    {
        swap(Arr[ 1 ], Arr[ i ]);
        heap_size = heap_size-1;
        max_heapify(Arr, 1, heap_size);
    }
}

// PRIORITY QUEUE