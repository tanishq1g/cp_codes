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


/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */

// The functions should be written in a way that array become sorted 
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[]. 
// n is size of heap. This function  is used in above heapSor()

void heapify(int arr[], int n, int i){
    int l = 2 * i + 1;
    int r = l + 1;
    int lr = i;
    if(l < n && arr[l] > arr[i]){
        lr = l;
    }
    if(r < n && arr[r] > arr[lr]){
        lr = r;
    }
    if(lr != i){
        swap(arr[i], arr[lr]);
        heapify(arr, n, lr);
    }
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  { 
    for(int i = n / 2; i >= 0; i--){
        heapify(arr, n, i);
    }
}
