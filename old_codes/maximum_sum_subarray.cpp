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

//O(n^2)
void largestsubarray1(int*a,int n,int *p,int *q,int *sum){
	int i,j;
	int msum=numeric_limits<int>::min();
	for(int i=0 ; i<n ; i++ ){
		int sum=0;
		for(int j=i ; j<n ; j++ ){
			sum+=a[j];
			if(sum>msum){
				msum=sum;
				*p=i;
				*q=j;
			}
		}
	}
	*sum=msum;
}

void maxdifflinear(int *a , int n, int *p , int *q , int *diff ){

	if(n==1){
		*p=0;
		*q=0;
		*diff=a[0];
		return;
	}
	int i=0,j=1;
	int min=i;
	int mdiff=a[j]-a[i];
	for(;j<n;j++){
		if(a[j]-a[min]>mdiff){
			mdiff=a[j]-a[min];
			*q=j;
		}

		if(a[j]<a[min]){
			min=j;
		}
	}	
	cout<<min<<'\n';
	*p=min+1;
	*diff=mdiff;

}

//O(n)+S(n)
void largestsubarray2(int*a,int n,int *p,int *q,int *sum){
	int i,j;
	int pi[n];
	pi[0]=a[0];
	for(i=1 ; i<n ; i++ ){
		pi[i]=pi[i-1]+a[i];
	}
	for(i=0 ; i<n ; i++ ){
		cout<<pi[i]<<' ';
	}
	cout<<'\n';
	maxdifflinear(pi,n,p,q,sum);
}

//O(n)+S(k)
void largestsubarray3(int*a,int n,int *p,int *q,int *sum){
	if(n==1){
		*p=0;
		*q=0;
		*sum=a[0];
		return;
	}
	int i=0,j=1;
	int pf=a[0];
	int pb=a[0];
	*p=i;
	int mdiff=a[0]+a[1];
	//cout<<"pf,pb,i,j"<<pf<<' '<<pb<<' '<<i<<' '<<j<<'\n';
	for(;j<n;j++){
	//	cout<<"pf,pb,i,j"<<pf<<' '<<pb<<' '<<i<<' '<<j<<'\n';
		pf=pf+a[j];
		if(pf-pb>mdiff){
			mdiff=pf-pb;
			*q=j;
		}
		if(pf<pb){
			*p=j;
			pb=pf;
		}
	}	
	*sum=mdiff;
	(*p)++;
}


int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int p,q,sum;
	largestsubarray1(a,n,&p,&q,&sum);
	cout<<"(p,q),sum - "<<p<<','<<q<<' '<<sum<<'\n';
	largestsubarray2(a,n,&p,&q,&sum);
	cout<<"(p,q),sum - "<<p<<','<<q<<' '<<sum<<'\n';
	largestsubarray3(a,n,&p,&q,&sum);
	cout<<"(p,q),sum - "<<p<<','<<q<<' '<<sum<<'\n';


	return 0;
}	