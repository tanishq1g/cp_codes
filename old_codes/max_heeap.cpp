#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

void mbottom_up_heapify(int *a,int in){
	int p=(in-1)/2;
	while(in>0){
		if(a[p]<a[in]){
			int t=a[p];
			a[p]=a[in];
			a[in]=t;
		}
		else 
			break;
		in=p;
		p=(in-1)/2;
	}

}

void mtop_bottom_heapify(int *a, int hl, int in){
	int l=2*in +1;
	int r=2*in +2,j;
	if(l==hl-1&&a[in]<a[l]){
		int t=a[l];
		a[l]=a[in];
		a[in]=t;
		return;
	}
	while(r<hl){
		if(a[l]>a[r])
			j=l;
		else
			j=r;
		if(a[in]>a[j])
			break;
		else{
			int t=a[j];
			a[j]=a[in];
			a[in]=t;
		}
		in=j;
		l=2*in+1;
		r=2*in+1;
		if(l==hl-1&&a[in]<a[l]){
			int t=a[l];
			a[l]=a[in];
			a[in]=t;
			break;	
		}
	}
		
}
void mheap_insert(int *a, int &hl, int ele){
	a[hl]=ele;
	mbottom_up_heapify(a,hl);
	hl++;
}

void mbuild_heap(int *a,int n){
	int i=n/2;
	while(i>=0){
		mtop_bottom_heapify(a,n,i);
		i--;
	}
}


void mdelete_max(int *a,int &n){
	int temp=a[n-1];
	a[n-1]=a[0];
	a[0]=temp;
	n--;
	mtop_bottom_heapify(a,n,0);
}


void mheapsort(int*a,int n){
	mbuild_heap(a,n);

	int n1=n;
	while(n1>0){
		mbuild_heap(a,n1);
		mdelete_max(a,n1);
	}
}

int main(){
	int a[100];
	int hl=0;
	int ele;
	int n;
	cin>>n;
	for(int i=0 ; i<n ; i++ ){
		cin>>a[i];
	}
	mheapsort(a,n);
	for(int i=0 ; i<n ; i++ ){cout<<a[i]<<' ';}cout<<'\n';
	return 0;
}