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
//Given an array of of size n and a number k, find all elements that appear more than n/k times
int majority(int*a,int n,int k){
	struct ele{
		int val;
		int count;
	};
	ele temp[k-1];
	int m=n/k;
	k--;
	for(int i=0 ; i<k ; i++ ){
		temp[i].count=0;
	}
	
	int flag;
	for( int i=0 ; i<n ; i++ ){
		flag=0;
		for( int j=0 ; j<k ; j++ ){
			if(temp[j].count==0){
				temp[j].val=a[i];
				temp[j].count++;
				flag=1;
				break;
			}
			else if(temp[j].val==a[i]){
				temp[j].count++;
				flag=1;
				break;
			}
		}
		if(flag==0){
			for(int j=0 ; j<k ; j++ ){
				temp[j].count--;
			}
		}
	}
	for (int i=0; i<k; i++){
        int ac = 0;  
        for (int j=0; j<n; j++)
            if (a[j] == temp[i].e)
                ac++;
        if (ac > m)
           cout << "Number:" << temp[i].e
                << " Count:" << ac << endl;
    }
}
int main(){
	int n;
	cin>>n;
	int a[n];
	int k;
	cin>>k;
	for(int i=0 ; i<n ; i++ ){
		cin>>a[i];
	}
	cout<<majority(a,n,k);
	return 0;
}	