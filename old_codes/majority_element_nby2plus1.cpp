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

int majority(int*a,int n){
	int ctr=0,x=a[0],m=n/2+1;
	for(int i=0 ; i<n ; i++ ){
		if(a[i]==x)
			ctr++;
		else if(ctr>0){
			ctr--;
		}
		else{
			x=a[i];
			ctr=1;
		}
	}
	ctr=0;
	int flag=0;
	for(int i=0 ; i<n ; i++ ){
		if(a[i]==x)
			ctr++;
		if(ctr>=m){
			flag=1;
			break;
		}
	}
	cout<<x<<' '<<ctr<<' '<<flag<<'\n';
	if(flag==1){
		return 1;
	}
	else 
		return 0;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0 ; i<n ; i++ ){
		cin>>a[i];
	}
	cout<<majority(a,n);
	return 0;
}	