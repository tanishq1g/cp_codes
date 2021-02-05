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

// array

// 3 way partitioning 

https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include <iostream>
using namespace std;

   0| 1 |   | 2
l m h
  l   mh
0 0 1 2 2

m++
a[l], a[m]
l++, m++
a[h], a[m]
h--, m++
int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int N;
	    cin>>N;
	    int A[N],B[N];
	    for(int j=0;j<N;j++)
	        cin>>A[j];
	    int pivot=0;
	    for(int j=0;j<N;j++)
	    {
	        if(A[j]==0)
	        {
	            B[pivot]=A[j];
	            pivot++;
	        }
	    }
	    for(int j=0;j<N;j++)
	    {
	        if(A[j]==1)
	        {
	            B[pivot]=A[j];
	            pivot++;
	        }
	    }
	    for(int j=0;j<N;j++)
	    {
	        if(A[j]==2)
	        {
	            B[pivot]=A[j];
	            pivot++;
	        }
	    }
	    for(int j=0;j<N;j++)
	        cout<<B[j]<<" ";
	    cout<<"\n";
	    
	}
	return 0;
	
}