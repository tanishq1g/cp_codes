#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	int k;
	
	for(int i=0 ; i<n ; i++ ){
		cin>>a[i];
	}
	cin>>k;
	if(k==1)
		for(int i=0 ; i<n ; i++ ){cout<<a[i]<<' ';}
	else{
		int m1=min(a[0],a[1]),m2=max(a[0],a[1]);
		for(int i=2 ; i<k ; i++ ){
			if(a[i]>m2){
				m1=m2;
				m2=a[i];
			}
			else if(a[i]>m1){
				m1=a[i];
			}
		}
		cout<<m2<<' ';
		for(int i=k ; i<n ; i++ ){
			if(a[i]>m2){
				// cout<<"if 1 ";
				if(a[i-k]==m2){
					m2=a[i];
				}
				else if(a[i-k]==m1){
					m1=m2;
					m2=a[i];
				}
				else{
					m1=m2;
					m2=a[i];
				}
			}
			else if(a[i]>m1){
				if ( a[i-k]==m2 ) {
					m2=a[i];
				}
				else if(a[i-k]==m1){
					m1=a[i];
				}
				else{
					m1=a[i];
				}
			}
			else{
				m1=min(a[i-k+1],a[i-k+2]),m2=max(a[i-k+1],a[i-k+2]);
				for(int j=i-k+3 ; j<i ; j++ ){
					if(a[j]>m2){
						m1=m2;
						m2=a[j];
					}
					else if(a[j]>m1){
						m1=a[j];
					}
				}
			}
		cout<<m2<<' ';
		}
	}
	
	return 0;
}