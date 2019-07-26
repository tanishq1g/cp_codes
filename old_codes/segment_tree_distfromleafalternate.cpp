#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <climits>
#include <list>
#include <stack>
#include <map>
using namespace std;
#define mod 1000000007;

void seg_build(unsigned long long *t,unsigned long long *a ,unsigned long long n,unsigned long long start,unsigned long long end, unsigned long long pos,int * index,int in){
	// cout<<"start"<<start<<"end"<<end<<"pos"<<pos<<'\n';
	if( start == end){
		t[pos] = a[start];
		// cout<<"s"<<t[pos]<<'\n';
	}
	else{
		int mid = ( start + end ) / 2;
		unsigned long long le=2*pos+1,ri=2*pos+2;
		seg_build(t,a,n,start,mid,le,index,in);
		seg_build(t,a,n,mid+1,end,ri,index,in);
		if(index[le]%2==in)
			t[pos] = t[le] | t[ri];
		else 
			t[pos] = t[le] ^ t[ri];
	}
}
 
void update(unsigned long long *t,unsigned long long *a,unsigned long long start, unsigned long long end, unsigned long long pos ,unsigned long long ind,unsigned long long val,int * index,int in){
	if(start == end){
		a[ind] = val;
		t[pos] = val;
	}
	else{
		unsigned long long mid = (start + end) / 2,le = 2*pos+1,ri=2*pos+2;
		update(t,a,start,mid,le,ind,val,index,in);
		update(t,a,mid+1,end,ri,ind,val,index,in);
		if(index[le]%2==in)
			t[pos] = t[le] | t[ri];
		else
			t[pos] = t[le] ^ t[ri];
	}
}
// unsigned long long seg_rangeminquery(unsigned long long *t,unsigned long long start,unsigned long long end, unsigned long long qlow, unsigned long long qhigh, unsigned long long pos,int * index,int in){
// 	if(qlow <= start && qhigh >= end)
// 		return t[pos];
// 	if(qlow > end || qhigh < start)
// 		return INT_MAX;
// 	unsigned long long mid = (start + end)/2;
// 	unsigned long long x1,x2;
// 	x1 = seg_rangeminquery(t,start,mid,qlow,qhigh,2*pos+1,index,in);
// 	x2 = seg_rangeminquery(t,mid+1,end,qlow,qhigh,2*pos+2,index,in);
// 	if(index[2*pos+1]%2 == in)
// 		return x1 | x2;
// 	else 
// 		return x1 ^ x2;
// }

int main(){
	unsigned long long n,m;
	cin >> n >> m;
	unsigned long long seg_s=2*pow(2,n)-1;

	int index[seg_s];
	unsigned long long i,j=0,k;
	for( i = 0; i <= n ; i++){
		k = 1 << i;
		while(k--){
			index[j++] = i;
		}	
	}

	// for(i = 0; i < seg_s; i++)cout<<i<<' '<<index[i]<<'\n';

	int in = n%2;
	n = 1<<n;
	unsigned long long a[n];
	for(i = 0; i < n; i++){
		cin >> a[i];
	}

    unsigned long long seg_a[seg_s];
    seg_build(seg_a,a,n,0,n-1,0,index,in);
    long long p,v,x,pt;
    //   for(int i = 0; i < seg_s; i++){
    // 	cout<<seg_a[i]<<' ';
    // }cout<<'\n';
    while(m--){
    	cin >> p >> v;
    	x = seg_s-n+p-1;
    	seg_a[x] = v;
    	pt = (x-1)/2;
    	while(pt > 0){
    		// cout<<pt<<' '<<x<<'\n';
    		if(x%2==1){
    			if(index[x]%2 == in)
    				seg_a[pt] = seg_a[x] | seg_a[x+1];
    			else
    				seg_a[pt] = seg_a[x] ^ seg_a[x+1];
    		}
    		else{
    			if(index[x]%2 == in)
    				seg_a[pt] = seg_a[x] | seg_a[x-1];
    			else
    				seg_a[pt] = seg_a[x] ^ seg_a[x-1];
    		}
    		x = pt;
    		pt = (x-1)/2;
    	}
    	// cout<<pt<<' '<<x<<'\n';
		if(x%2==1){
			if(index[x]%2 == in)
				seg_a[pt] = seg_a[x] | seg_a[x+1];
			else
				seg_a[pt] = seg_a[x] ^ seg_a[x+1];
		}
		else{
			if(index[x]%2 == in)
				seg_a[pt] = seg_a[x] | seg_a[x-1];
			else
				seg_a[pt] = seg_a[x] ^ seg_a[x-1];
		}
    // for(int i = 0; i < seg_s; i++){
    // 	cout<<seg_a[i]<<' ';
    // }cout<<'\n';
    cout<<seg_a[0]<<'\n';	
    }
    // for(int i = 0; i < seg_s; i++){
    // 	cout<<seg_a[i]<<' ';
    // }
	return 0;
 
} 