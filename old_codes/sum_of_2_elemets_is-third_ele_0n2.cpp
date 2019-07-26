#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
//a_i+a_j=a_k
using namespace std;
int binarysearch(int * a,int first,int last,int key){
	int mid;
	while(first<=last){
		mid=(first+last)/2;
		if (a[mid]==key)
			return mid;
		else if(a[mid]<key)
			first=mid+1;
		else
			last=mid-1;
	
	}
	return -1;

}

int m(int *a,int n,int x){
	int count=0;
	int l,r;
	for(int i=0;i<n;i++){
		l=0;
		r=n-1;
		while(l<=r){
			cout<<"l- "<<l<<" r-"<<r<<" i-"<<i<<'\n';
			cout<<a[l]<<" +"<<a[r]<<" ="<<a[i]<<' '<<'\n';

			if(a[l]+a[r]==a[i]){
				cout<<a[l]<<".............. +"<<a[r]<<" ="<<a[i]<<' '<<'\n';
				count++;
				l++;
				r--;
			}
			else if(a[l]+a[r]<a[i])
				l++;
			else
				r--;
		}
	}
	
}
int main() {
    
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	int x;
	cin>>x;
	clock_t start,stop;
	start=clock();
	sort(a,a+n);
	for (int i = 0; i < n; ++i)
		cout<<a[i]<<' ';
	cout<<m(a,n,x);
	stop=clock();	
	cout<<'\n'<<"time taken-"<<double(stop-start)/ CLOCKS_PER_SEC;
    return 0;
}	