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


void countingsort(int *a,int *b,int n){
	int c[n]={0};
	for(int i=0 ; i<n ; i++ ){
		c[a[i]]++;
	}
	

	for(int i=1 ; i<n ; i++ ){
		c[i]+=c[i-1];
	}
	

	for(int i=n-1 ; i>=0 ; i-- ){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	for(int i=0 ; i<n ; i++ ){cout<<b[i]<<' ';}cout<<'\n';
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int b[n];
	countingsort(a,b,n);

	return 0;
}	