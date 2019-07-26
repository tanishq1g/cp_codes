#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <queue>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	n++;
	for(int i=1; i<n; i++){
		cin >> a[i];
	}
	int i = 1,flag = 0,pos1,pos2; 
	while(a[i]<=a[i+1] && i<n-1){
			i++;			
	}
	if(i == n-1)
		cout<<"yes\n1 1";
	else{
		pos1 = i;
		while(a[i] > a[i+1] && i<n-1){
				i++;			
		}
		if ( i == n - 1){
			if(pos1 == 1)
				cout << "yes\n1 "<<n-1;
			else if(a[n-1] >= a[pos1 - 1])
				cout << "yes\n"<<pos1<<' '<<n-1;
			else
				cout << "no''";
		}
		else{
			pos2 = i;
			while(a[i]<=a[i+1] && i<n-1){
				i++;			
			}
			if(i == n-1)
				if(a[pos2] >= a[pos1-1] && a[pos1] <= a[pos2+1])
					cout<<"yes\n"<<pos1<<' '<<pos2;
				else
					cout<<"no";
			else
				cout<<"no";
		}
	}
}