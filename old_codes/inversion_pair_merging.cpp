#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

//i<j but a_i > a_j
//mid -i+1 ---tels that mid - #a_i elemnts are greater than a_j
int merge(int *a,int *b, int start, int mid , int end){
mid_i=1	cout<<"start,mid,end-"<<start<<' '<<mid<<' '<<end<<'\n';
	int i,j,k;
	int count=0;
	cout<<"..count-"<<count<<'\n';

	for(i=start,j=mid+1,k=start;i<=mid && j<=end;k++){
		cout<<"a[i],a[j]-"<<a[i]<<' '<<a[j]<<'\n';
		if(a[i]>a[j]){
			b[k]=a[j++];
			count+=mid-i+1;

		}	
		else{

			b[k]=a[i];
			i++;
		}
	}
	cout<<".count-"<<count<<'\n';
	while(i<=mid){
		b[k]=a[i];
			//count+=mid-i;
		
		k++;i++;	
	}
	cout<<"..count-"<<count<<'\n';

	while(j<=end)
		b[k++]=a[j++];
	cout<<"...count-"<<count<<'\n';

	for(i=start;i<=end;i++){
		a[i]=b[i];
		cout<<a[i]<<' ';
	}
	cout<<"\n....count-"<<count<<'\n';
	return count;
}


int insertionpair(int *a,int *b,int i,int j){
	cout<<"insertion pair i,j"<<i<<' '<<j<<'\n';
	if(j<=i)
		return 0;
	else{
		int k=(i+j)/2;
		return insertionpair(a,b,i,k)+insertionpair(a,b,k+1,j)+merge(a,b,i,k,j);
	}
	
}
int main() {
    
	int n;
	cin>>n;
	int a[n],b[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	clock_t start,stop;
	start=clock();

	cout<<insertionpair(a,b,0,n-1);
	stop=clock();	
	cout<<'\n'<<"time taken-"<<double(stop-start)/ CLOCKS_PER_SEC;
    return 0;
}	