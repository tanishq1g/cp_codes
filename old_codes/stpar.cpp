#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
	while(1){
		int n;
		cin>>n;
		if(n==0)
			break;
		int a[n];
		for(int i=0 ; i<n ; i++ ){cin>>a[i];}
		int b[n];
		int l=0;
		int var=1;
		for(int i=0 ; i<n ; i++ ){
			if(a[i]!=var){
				b[l++]=a[i];
			}
			else{
				var++;
				while(b[l-1]==var){
					l--;
					var++;
				}
			}

		}
		while(l!=0){
			if(a[l-1]==var){
				l--;
				var++;
			}
			else
				break;
		}
		if (l==0)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}