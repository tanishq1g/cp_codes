#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;
int partition(int *a,int i,int j,int p){
	int l=i;int r=j;
	while(1){
		while(a[l]<=p)
			l++;
		while(a[r]>p)
			r--;
		if(l>r)
			break;
		int t=a[l];
		a[l]=a[r];
		a[r]=t;
		l++;r--;
	}
	return r;
}

int findele(int *a,int i,int j,int r,int n){
	if(j==i+1){
		if(n-j==r)
			return j;
		else if(n-i==r)
			return i;
	}
	else if(j<=i){
		if(n-i==r)
			return i;
	}
	else{
		int p=(rand()%(j-i+1))+i;
		int k=partition(a,i,j,a[p]);
		if(n-k==r)
			return p;
		else if(n-k<r)
			findele(a,i,k,r,n);
		else
			findele(a,k+1,j,r,n);
	}
}
int main() {
    
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	int r;
	cin>>r;
	clock_t start,stop;
	start=clock();
	int x=findele(a,0,n-1,r,n);
	cout<<"ele is"<<a[x]<<'\n';
	stop=clock();
	for (int i = 0; i < n; ++i)
		cout<<a[i]<<' ';
	cout<<'\n'<<"time taken-"<<double(stop-start)/ CLOCKS_PER_SEC;
    return 0;
}	