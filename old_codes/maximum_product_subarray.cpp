#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
void maxproductsubarray(int *a,int n){
	int i=0;
	int ans=1;
	int p1=1;
	while(i<n&&p1>0){
		p1=p1*a[i];
		i++;
		if(ans<p1)
			ans=p1;
	}
	int p2=1,k;
	while(i<n){
		p2=p2*a[i];
		i++;
		if(p2>ans){
			ans=p2;
		}
		k=p1*p2;
		if(k>ans){
			ans=k;
		}
		if(p2==0)
			p2=1;
	}
	cout<<ans;
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];

	maxproductsubarray(a,n);

	return 0;
}