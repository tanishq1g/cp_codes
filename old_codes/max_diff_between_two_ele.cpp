#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
//Maximum difference between two elements such that larger element appears after the smaller number
//O(n^2)
int maxDiff(int arr[], int arr_size) 
{     
  int max_diff = arr[1] - arr[0];
  int i, j;
  for(i = 0; i < arr_size; i++)
  {
    for(j = i+1; j < arr_size; j++)
    {        
      if(arr[j] - arr[i] > max_diff)   
         max_diff = arr[j] - arr[i];
    }    
  }          
  return max_diff;
}    
//a_i+a_j is max but i<j
int maxdifflinear(int *a , int n){
	int min=a[0];
	if(n==1)
		return 0;
	int mdiff=a[1]-a[0];
	for(int i=1;i<n;i++){
		if(a[i]-min>mdiff)
			mdiff=a[i]-min;
		if(a[i]<min)
			min=a[i];
	}	
	return mdiff;
}

//a_i+a_j is max but i<j+l;

int maxdifflinear1( int * a , int n , int l ){
	int min=a[0];
	if(n==1)
		return 0;
	int mdiff=a[1]-a[0];
	for(int i=1;i<n;i++){
		if(a[i]-min>mdiff)
			mdiff=a[i]-min;
		if(a[i-l+1]<min)
			min=a[i-l+1];
	}	
	return mdiff;
}

//a_i+a_j is max but i < j < i+l;

int maxdifflinear2( int * a , int n , int l ){
	int min=0,max=0;
	if(n==1)
		return 0;
	int mdiff=a[1]-a[0];
	for(int i=1;i<n;i++){
		if(a[i]-a[min]>mdiff){
			mdiff=a[i]-a[min];
			max=i;
		}
		if(i==min+l){
			min=max+1;
		}
		if(a[i]<a[min]){
			min=i++;
		}
	}	
	cout<<"min,  max"<<min<<' '<<max<<'\n';
	return mdiff;
}


int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	cout<<"a_i+a_j is max but i<j"<<'\n';
	cout<<maxdifflinear(a,n)<<'\n';
	int l;
	cin>>l;

	cout<<"\na_i+a_j is max but i<=j+l"<<'\n';
	cout<<maxdifflinear1(a,n,l);
	cout<<"\na_i+a_j is max but i<j<i+l"<<'\n';
	cout<<maxdifflinear2(a,n,l);

	return 0;
}	