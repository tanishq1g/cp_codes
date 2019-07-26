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
using namespace std;


// void swap(int *a,int i,int j){
// 	int temp=a[i];
// 	a[i]=a[j];
// 	a[j]=temp;
// }	

// bool func(int a,int b){return a>b;}
// struct order{
// 	int t;
// 	int d;
// };
// bool funcstruct(snake &a,snake &b){
// 	return a.d<b.d;
// }
// long int binarysearch(long int * a,int first,int last,int key){
// 	int mid;
// 	while(first<=last){
// 		mid=(first+last)/2;
// 		if (a[mid]==key)
// 			return mid;
// 		else if(a[mid]<key)
// 			first=mid+1;
// 		else
// 			last=mid-1;
	
// 	}
// 	return first;
// }


void mbottom_up_heapify(long int *a,int in){
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

void mtop_bottom_heapify(long int *a, int hl, int in){
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
void mheap_insert(long int *a, int &hl, int ele){
	a[hl]=ele;
	mbottom_up_heapify(a,hl);
	hl++;
}

void mbuild_heap(long int *a,int n){
	int i=n/2;
	while(i>=0){
		mtop_bottom_heapify(a,n,i);
		i--;
	}
}


void mdelete_max(long int *a,int &n){
	int temp=a[n-1];
	a[n-1]=a[0];
	a[0]=temp;
	n--;
	mtop_bottom_heapify(a,n,0);
}


void mheapsort(long int*a,int n){
	mbuild_heap(a,n);

	int n1=n;
	while(n1>0){
		mbuild_heap(a,n1);
		mdelete_max(a,n1);
	}
}
//min heap
void bottom_up_heapify(long int *a,int in){
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

void top_bottom_heapify(long int *a, int hl, int in){
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
void heap_insert(long int *a, int &hl, int ele){
	a[hl]=ele;
	bottom_up_heapify(a,hl);
	hl++;
}

void build_heap(long int *a,int n){
	int i=n/2;
	while(i>=0){
		top_bottom_heapify(a,n,i);
		i--;
	}
}


void delete_min(long int *a,int &n){
	int temp=a[n-1];
	a[n-1]=a[0];
	a[0]=temp;
	n--;
	top_bottom_heapify(a,n,0);
}


void heapsort(long int*a,int n){
	build_heap(a,n);

	int n1=n;
	while(n1>0){
		build_heap(a,n1);
		delete_min(a,n1);
	}
}


int main(){
	int t;
	cin >> t;
	for(int w=0; w<t; w++){
		long int ele;
		long int min[100001],max[100001];
		int n1 = 0,n2 = 0;
		int med = 1;
		cin >> ele;
		if(ele == 0)
			continue;
		heap_insert(min,n1,ele);
		while(1){
			cin>>ele;
			if(ele == 0)
				break;
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
				// cout<<'\n';
				// cout<<"   MIN   ";
				// for(int k=0 ; k<n1 ; k++ ){cout<<min[k]<<' ';}
				// cout<<'\n';
				// cout<<"   Max   ";
				// for(int k=0 ; k<n2 ; k++ ){cout<<max[k]<<' ';}
				// cout<<'\n';
			}
			else{
				if(n1 == 0 && n2 == 0)
					break;
				if(n1>n2)
				{
					cout<<min[0]<<"\n";
					delete_min(min,n1);
				}
				else if(n1<n2)
				{
					cout<<max[0]<<"\n";
					mdelete_max(max,n2);
				}
				else
				{
					if(min[0]>max[0]){
						cout<<max[0]<<"\n";
						mdelete_max(max,n2);
					}
					else{
						cout<<max[0]<<"\n";
						mdelete_max(max,n2);
					}
				}
			}
		}
		if(w != t-1)
			cout<<'\n';
	}

}















