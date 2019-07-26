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

int binarysearch(int * a,int first,int last,int key,int n){
	int mid;
	while(first<=last){
		mid=(first+last)/2;
		
		if (a[mid]==key)
			return mid;
		if(first==last-1){
			if(a[last]<key)
				return last+1;
			return last;
		}
		if(a[mid]<key)
			first=mid+1;
		else
			last=mid-1;
	
	}
}
int counttriangletriplets(int *a,int n){
	int ctr=0,su,count=0,b;
	for(int i=2;i<n;i++){
		for(int j=0,k=i-1;j<k;j++){
			su=a[k]+a[j];
			if(su>a[i]){	
				//cout<<"i :"<<i<<" j :"<<j<<" k :"<<k<<" su :"<<su;
				b=binarysearch(a,i+1,n-1,su,n);
				//cout<<" b :"<<b<<'\n';
				//cout<<"b-i :"<<b-i<<'\n';
				count+=b-i;
				//cout<<count<<'\n';
			}
		}
	}
	return count;
}
int main(){
	int n=-1;
	while(1){
		cin>>n;
		if(n==0)
			break;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		
		cout<<counttriangletriplets(a,n)<<'\n';
	}
	return 0;
}	