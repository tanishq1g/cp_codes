#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

void countingsort(int n,long int a[][7],long int b[][7],int d,int in){
	int c[10]={0};
	for(int i=0 ; i<n ; i++ ){
		c[(a[i][in]/d)%10]++;
	}

	for(int i=1 ; i<10 ; i++ ){
		c[i]+=c[i-1];
	}

	
	int temp;
	for(int i=n-1 ; i>=0 ; i-- ){
		temp=(a[i][in]/d)%10;
		for(int k=0 ; k<6 ; k++ ){
			b[c[temp]-1][k]=a[i][k];
		}
		c[temp]--;
	}
	for(int i=0 ; i<n ; i++ ){
		for(int j=0 ; j<6 ; j++ ){
			a[i][j]=b[i][j];
		}

	}
}

void radixsort(int n,long int a[][7],long int b[][7]){
	for(int i=5 ; i>=2 ; i-- ){
		countingsort(n,a,b,1,i);
		countingsort(n,a,b,10,i);
		countingsort(n,a,b,100,i);
		countingsort(n,a,b,1000,i);
	}

	countingsort(n,a,b,1,1);
	countingsort(n,a,b,10,1);
	countingsort(n,a,b,100,1);
	countingsort(n,a,b,1000,1);
	countingsort(n,a,b,10000,1);
	countingsort(n,a,b,100000,1);
	countingsort(n,a,b,1000000,1);
	countingsort(n,a,b,10000000,1);

	countingsort(n,a,b,1,0);
	countingsort(n,a,b,10,0);
	for(int i=0 ; i<6 ; i++ ){
		b[0][i]=a[0][i];
	}

	int c=1,flag=0,pos,k=0;
	for(int i=0 ; i<n ; i++ ){
		for(int j=0 ; j<6 ; j++ ){
			if(b[i][j]!=b[i+1][j]){
				flag=1;
				break;
			}
		}
		if(i==n-2){
			if(flag==0){
				for(int j=0 ; j<6 ; j++ ){
					a[k][j]=b[i][j];
				}
				a[k][6]=c+1;
				k++;
				break;	
			}	
			else{
				for(int j=0 ; j<6 ; j++ ){
					a[k][j]=b[i][j];
				}
				a[k][6]=c;
				k++;
				i++;
				for(int j=0 ; j<6 ; j++ ){
					a[k][j]=b[i][j];
				}
				a[k][6]=1;
				k++;
				break;
			}
		}
		if(flag==0){
			c++;
		}
		else{
			for(int j=0 ; j<6 ; j++ ){
				a[k][j]=b[i][j];
			}
			a[k][6]=c;
			k++;
			c=1;
			flag=0;
		}
		
	}

	for(int i=0 ; i<k ; i++ ){
		for(int j=0 ; j<7 ; j++ ){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}

}

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int ti=0 ; ti<t ; ti++ ){
		int n;
		cin>>n;
		long int a[n][7],b[n][7];
		for(int i=0 ; i<n ; i++ ){
			for(int j=0 ; j<6 ; j++ ){
				cin>>a[i][j];
			}
		}
		radixsort(n,a,b);	
	}

	return 0;
}