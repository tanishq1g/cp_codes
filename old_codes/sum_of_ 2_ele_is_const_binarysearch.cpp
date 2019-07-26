#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>

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

void m2(int *a,int n,int x,int *p,int *q){
	int k;
	*p=-1;
	*q=-1;
	for(int i=0;i<n-1;i++){
		k=binarysearch(a,0,n-1,x-a[i]);
		if(k!=-1){
			*p=i;
			*q=k;
			break;
		}
	}
	
}
int main() {
    
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	int x,p,q;
	cin>>x;
	clock_t start,stop;
	start=clock();
	sort(a,a+n);
	for (int i = 0; i < n; ++i)
		cout<<a[i]<<' ';
	m2(a,n,x,&p,&q);

	cout<<"(p,q,x):"<<p<<' '<<q<<' '<<x<<'\n';
	stop=clock();
	
	cout<<'\n'<<"time taken-"<<double(stop-start)/ CLOCKS_PER_SEC;
    return 0;
}	

/*counting all the pairs whose sum is x

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
int binarysearch(int * a,int first,int last,int key){
	int mid;
	while(first<=last){
		mid=(first+last)/2;
		if (a[mid]==key){
			//cout<<"found"<<a[mid]<<'\n';
			return 1;
		}
		else if(a[mid]<key)
			first=mid+1;
		else
			last=mid-1;
	
	}
	return 0;

}
void m2(int *a,int n,int x,int *count){
	for(int i=0;i<n-1;i++){
		//cout<<"a[i]"<<a[i]<<' '<<"count"<<*count<<'\n';	
		//cout<<x-a[i]<<'\n';
		(*count)+=binarysearch(a,i+1,n-1,x+a[i]);
		//cout<<a[i]-x<<'\n';
		//(*count)+=binarysearch(a,0,n-1,a[i]-x);	
	}
	
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int x,count=0;
	cin>>x;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	sort(a,a+n);
	m2(a,n,x,&count);
	cout<<count;
	return 0;
}

*/