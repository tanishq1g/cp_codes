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
#include <iomanip>
#include <climits>
#include <list>
 
using namespace std;
#define MOD 1000000007
//o(n2)
// void dp_lic(vector <int> &arr){
// 	vector <vector <int> > v(arr.size());
// 	v[0].push_back(arr[0]);
// 	for(int i = 1; i < arr.size(); i++){
// 		for(int j = 0; j < i; j++){
// 			if(arr[j] <= arr[i] && (v[i].size() < v[j].size() + 1)){
// 				v[i] = v[j];
// 			}
// 		}
// 		v[i].push_back(arr[i]);
// 		cout<<arr[i]<<" - ";
// 		for(int j = 0; j < v[i].size(); j++){
// 			cout<<v[i][j]<<' ';
// 		}
// 		cout<<'\n';
// 	}
// 	int max = 0;
// 	for(int i = 0; i < arr.size(); i++){
// 		if(v[i].size() > max)
// 			max = v[i].size();
// 		//cout<<v[i].size()<<' '<<max<<'\n';

// 	}
// 	cout<<max;
// }
//o(nlogn)
int binarysearch(vector <int> &length,vector <int> &arr,int first,int last,int key){
	int mid;
	while(first<=last){
		mid=(first+last)/2;
		if (arr[length[mid]]==key)
			return mid;
		else if(arr[length[mid]]<key)
			first=mid+1;
		else
			last=mid-1;
	
	}
	return first;
}
void dp_lic(vector <int> &arr){
	vector <int> length(arr.size());
	int len = 0;
	vector <int> retrace(arr.size(),-1);
	length[0] = 0;
	len++;
	for(int i = 1; i < arr.size(); i++){
		if(arr[i] < arr[length[0]]){
			// cout<<"a\n";
			length[0] = i;
		}
		else if(arr[i] > arr[length[len-1]]){
			// cout<<"b\n";
			length[len] = i;
			retrace[i] = length[len-1];
			len++;
		}
		else{
			// cout<<"c\n";
			int k = binarysearch(length,arr,0,len-1,arr[i]);
			length[k] = i;
			retrace[i] = length[k-1];
		}
		cout<<arr[i]<<'\n';
		for(int j = 0; j < len; j++){
			cout<<length[j]<<' ';
		}
		cout<<'\n';
		for(int j = 0; j < arr.size(); j++){
			cout<<retrace[j]<<' ';
		}
		cout<<'\n';
	}
	cout<<len<<'\n';
	int temp = len - 1;
	cout<<arr[length[temp]]<<' ';
	temp = retrace[length[temp]];
	while(temp != -1){
		cout<<arr[temp]<<' ';
		temp = retrace[temp]; 
	}
}
int main(){
	int n;
	cin >> n;
	vector <int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	dp_lic(arr);
	return 0;
} 