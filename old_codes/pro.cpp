#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;


void swap(int *a,int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}	
void reverse(int *a,int start,int end){
	int i=start,j=end;
	while(i<j){
		swap(a,i,j);
		i++;
		j--;
	}
}
void merge(int *a,int *b, int start, int mid , int end){
	int i,j,k;
	for(i=start,j=mid+1,k=start;i<=mid && j<=end;k++){
		if(a[i]>=a[j])
			b[k]=a[j++];
		else
			b[k]=a[i++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=end)
		b[k++]=a[j++];
	for(i=start;i<=end;i++)
		a[i]=b[i];
	
}
/*
void step3(int *a,int n,int *c,int n2,int start,int end){
	if(start>=end);
	else{
		int mid;
		mid=start+(end-start)/2;
		mergesort(a,b,start,mid);
		mergesort(a,b,mid+1,end);
		merge(a,b,start,mid,end);

	}
}*/
void step1(int*a,int n,int *c,int *n2){
	int p,q;
	for(int i=0 ; i<n-1 ; i++ ){

		if(a[i]>a[i+1]){
			p=i+1;q=i+1;
			while(i<n){
				i++;
				if(a[i]<a[i+1]){
					q=i;
					break;
				}

			}
			if(i==n-1)
				q=n-1;
			if(p!=q){
				reverse(a,p,q);
			}
		}
	}
	*n2=0;
	c[*n2]=0;
	(*n2)++;
	for(int i=0 ; i<n-1 ; i++ ){
		if(a[i]>a[i+1]){
			c[*n2]=i;
			(*n2)++;
			c[(*n2)]=i+1;
			(*n2)++;
		}
	}
	c[*n2]=n-1;
	(*n2)++;
}
int main(){
	int n,n2;
	cin>>n;
	int a[n],c[n];
	for(int i=0 ; i<n ; i++ ){
		cin>>a[i];
	}
	step1(a,n,c,&n2);
	for(int i=0 ; i<n ; i++ ){cout<<a[i]<<' ';}cout<<'\n';
	for(int i=0 ; i<n2 ; i++ ){cout<<c[i]<<' ';}cout<<'\n';
	int ch[n2]={1};
	int count=n2;
	int b[n];
	//complexity nlogn
	//i wanted to use linked list here but was not able to i told you that 
	while(count>2){
		int x,y,z,l;
		int j=0;
		for(int i=3 ; i<n2 ; ){
			if(ch[i-3]==1)
				x=i-3;
			else{
				i++;
				continue;
			}
			if(ch[i-2]==1)
				y=i-2;
			else{
				i++;
				continue;
			}
			if(ch[i-1]==1)
				l=i-1;
			else{
				i++;
				continue;
			}
			if(ch[i]==1)
				z=i;
			else{
				i++;
				continue;
			}
			merge(a,b,c[x],c[y],c[z]);
			ch[x]=0;
			ch[y]=0;
			ch[z]=0;
			ch[l]=0;
			count-=4;
			i+=4;
			for(int i=0 ; i<n ; i++ ){cout<<a[i]<<' ';}cout<<'\n';

		}
	}
	for(int i=0 ; i<n ; i++ ){cout<<a[i]<<' ';}cout<<'\n';

	return 0;
}