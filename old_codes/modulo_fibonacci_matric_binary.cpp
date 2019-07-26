#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

//for thousand digit number
void mm(int to[2][2],int fr[2][2]){
	int a,b,c,d;
	a=(to[0][0]*fr[0][0]+to[0][1]*fr[1][0])%100;
	b=(to[0][0]*fr[0][1]+to[0][1]*fr[1][1])%100;
	c=(to[1][0]*fr[0][0]+to[1][1]*fr[1][0])%100;
	d=(to[1][0]*fr[0][1]+to[1][1]*fr[1][1])%100;
	to[0][0]=a;
	to[0][1]=b;
	to[1][0]=c;
	to[1][1]=d;
	cout<<"a,b,c,d--"<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
}
void decimaltobin(int *no,int s,int *bi,int m){
	int che=s-1;
	int k=m-1;
	for(int j=0;j<s-1;){
		bi[k--]=no[che]%2;
		for(int i=j;i<s;i++){
			no[i+1]+=(no[i]%2)*10;
			no[i]=no[i]/2;
		}
		if(no[j]==0){
			j++;
		}
	}
	while(no[che]!=1){
		bi[k--]=no[che]%2;
		no[che]=no[che]/2;
	}
	bi[k--]=no[che]%2;
	for (int i = 0; i < m; ++i)
	{
		cout<<bi[i]<<' ';
	}
	cout<<'\n';
}
int power3(int *bi,int m,int a[2][2]){
	int y[2][2]={{1,0},{0,1}};
	int i=m-1;
	while(i>=0){
		if(bi[i]==1)
			mm(y,a);
		mm(a,a);
		i--;
	}	
	return y[1][0];
}
int main(){
	int s;
	cin >> s;
	int no[s];
	//to fill the array randomly
	for (int i = 0; i<s;++i){
		//no[i]=rand()%10;
		cin>>no[i];
		cout<<no[i]<<' ';
	}
	cout<<'\n';
	int m=s*log2(10)+1;
	cout<<"m-"<<m<<'\n';
	int bi[m];
	decimaltobin(no,s,bi,m);
	int a[2][2]={{1,1},{1,0}};
	cout<<power3(bi,m,a);


	return 0;
}