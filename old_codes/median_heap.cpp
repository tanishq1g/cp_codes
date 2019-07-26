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
//min heap
void bottom_up_heapify(int *a,int in){
	int p=(in-1)/2;
	while(in>0){
		if(a[p]>a[in]){
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

void top_bottom_heapify(int *a, int hl, int in){
	int l=2*in +1;
	int r=2*in +2,j;
	if(l==hl-1&&a[in]>a[l]){
		int t=a[l];
		a[l]=a[in];
		a[in]=t;
		return;
	}
	while(r<hl){
		if(a[l]<a[r])
			j=l;
		else
			j=r;
		if(a[in]<a[j])
			break;
		else{
			int t=a[j];
			a[j]=a[in];
			a[in]=t;
		}
		in=j;
		l=2*in+1;
		r=2*in+1;
		if(l==hl-1&&a[in]>a[l]){
			int t=a[l];
			a[l]=a[in];
			a[in]=t;
			break;	
		}
	}
		
}
void heap_insert(int *a, int &hl, int ele){
	a[hl]=ele;
	bottom_up_heapify(a,hl);
	hl++;
}

void build_heap(int *a,int n){
	int i=n/2;
	while(i>=0){
		top_bottom_heapify(a,n,i);
		i--;
	}
}


void delete_min(int *a,int &n){
	int temp=a[n-1];
	a[n-1]=a[0];
	a[0]=temp;
	n--;
	top_bottom_heapify(a,n,0);
}


void heapsort(int*a,int n){
	build_heap(a,n);

	int n1=n;
	while(n1>0){
		build_heap(a,n1);
		delete_min(a,n1);
	}
}


int main(){
	int n;
	cin>>n;
	int ele;
	int min[n],max[n];
	int n1=0,n2=0;
	int med=1;
	cin>>ele;
	heap_insert(min,n1,ele);
	for(int i=1 ; i<n ; i++ ){
		cin>>ele;
		if(ele!=-1){
			if(n1>n2){
				med=1;
			}
			else{
				med=2;
			}
			if(med==1){
				if(min[0]>ele)
					mheap_insert(max,n2,ele);
				else
					heap_insert(min,n1,ele);
			}
			else{
				if(max[0]>ele)
					mheap_insert(max,n2,ele);
				else
					heap_insert(min,n1,ele);
			}
			if(n1-n2>1){
				mheap_insert(max,n2,min[0]);
				delete_min(min,n1);
			}
			if(n2-n1>1){
				heap_insert(min,n1,max[0]);
				mdelete_max(max,n2);	
			}
			cout<<'\n';
			cout<<"   MIN   ";
			for(int k=0 ; k<n1 ; k++ ){cout<<min[k]<<' ';}
			cout<<'\n';
			cout<<"   Max   ";
			for(int k=0 ; k<n2 ; k++ ){cout<<max[k]<<' ';}
			cout<<'\n';
		}
		else{
			if(n1>n2)
			{
				cout<<min[0]<<" is the med\n";
				delete_min(min,n1);
			}
			else if(n1<n2)
			{
				cout<<max[0]<<" is the med\n";
				mdelete_max(max,n2);
			}
			else
			{
				if(min[0]>max[0]){
					cout<<max[0]<<" is the med\n";
					mdelete_max(max,n2);
				}
				else{
					cout<<max[0]<<" is the med\n";
					mdelete_max(max,n2);
				}
			}
		}
	}
	return 0;		
}