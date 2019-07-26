#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
//a_i +a_j=X


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

void rqs(int *a,int i,int j){
	if(j==i+1){
		if(a[j]<a[i]){
			int temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	else if(j<=i);
	else{
		int p=(rand()%(j-i+1))+i;
		cout<<p<<'\n';
		int k=partition(a,i,j,a[p]);
		rqs(a,i,k);
		rqs(a,k+1,j);
	}
}
int main() {
    
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	clock_t start,stop;
	start=clock();
	rqs(a,0,n-1);
	stop=clock();
	for (int i = 0; i < n; ++i)
		cout<<a[i]<<' ';
	cout<<'\n'<<"time taken-"<<double(stop-start)/ CLOCKS_PER_SEC;
    return 0;
}	