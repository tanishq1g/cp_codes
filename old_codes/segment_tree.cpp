#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;

void seg_min_build(int *t, int s, int *a , int n, int start, int end, int pos){
	cout<<"start"<<start<<"end"<<end<<"pos"<<pos<<'\n';
	if( start == end){
		t[pos] = a[start];
		cout<<"s"<<t[pos]<<'\n';
	}
	else{
		int mid = ( start + end )/2;
		seg_min_build(t,s,a,n,start,mid,2*pos+1);
		seg_min_build(t,s,a,n,mid+1,end,2*pos+2);
		t[pos] = min(t[2*pos+1],t[2*pos+2]);
	}
}
 

int seg_rangeminquery(int *t,int start, int end, int qlow, int qhigh, int pos){
	if(qlow <= start && qhigh >= end)
		return t[pos];
	if( qlow > end || qhigh <start)
		return INT_MAX;
	int mid = (start + end)/2;
	return min(seg_rangeminquery(t,start,mid,qlow,qhigh,2*pos+1), seg_rangeminquery(t,mid+1,end,qlow,qhigh,2*pos+2));
}

void seg_updaterangelazy(int *t,int *lazy,int start,int end, int qlow, int qhigh, int val, int pos){
	if(start > end)
		return;
	if(lazy[pos] != 0){
		t[pos] += lazy[pos];
		if ( start != end ){
			lazy[2*pos + 1] += lazy[pos];
			lazy[2*pos + 2] += lazy[pos];
		}
		lazy[pos]=0;
	}
	if(start > qhigh || end < qlow)
		return;
	if(qlow <= start&& qhigh >= end ){
		t[pos] += val;
		if ( start != end){
			lazy[2*pos + 1] += val;
			lazy[2*pos + 2] += val;
		}
		return;
	}

	int mid = (start + end)/2;
	seg_updaterangelazy(t,lazy,start,mid,qlow,qhigh,val,2*pos+1);
	seg_updaterangelazy(t,lazy,mid+1,end,qlow,qhigh,val,2*pos+2);
	t[pos] = min(t[2*pos + 1], t[2*pos + 2]);

}
int main(){
	int n;
	cin>>n;
	int a[n];
	for ( int i =0; i < n; i++)
		cin>>a[i];
	int seg_s=2*pow(2,ceil(log2(n)))-1;
	int seg_a[seg_s];
	seg_min_build(seg_a,seg_s,a,n,0,n-1,0);
	for(int i=0; i<seg_s; i++)
		cout<<seg_a[i]<<' ';
	cout<<'\n';
	
	cout<<seg_rangeminquery(seg_a,0,n-1,1,4,0);
	cout<<'\n';

	int seg_lazy[seg_s];
	for(int i=0; i<seg_s; i++){
		seg_lazy[i]=0;
	}

	seg_updaterangelazy(seg_a,seg_lazy,0,n-1,0,3,2,0);
	for(int i=0; i<seg_s; i++)
		cout<<seg_a[i]<<' ';
	cout<<'\n';
	for(int i=0; i<seg_s; i++)
		cout<<seg_lazy[i]<<' ';
	cout<<'\n';

	seg_updaterangelazy(seg_a,seg_lazy,0,n-1,2,2,4,0);
	for(int i=0; i<seg_s; i++)
		cout<<seg_a[i]<<' ';
	cout<<'\n';
	for(int i=0; i<seg_s; i++)
		cout<<seg_lazy[i]<<' ';
	cout<<'\n';	

	cout<<seg_rangeminquery(seg_a,0,n-1,1,2,0);


}







