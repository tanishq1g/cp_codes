#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int power1(int x,int n){
	if(n==0)
		return 1;
	if(n%2==0)
		return power1(x*x,n/2);
	else
		return x*power1(x*x,n/2);
}

int power2(int x,int n){
	int y=1;
	while(n>0){
		if(n%2==1)
			y=y*x;
		x=x*x;
		n=n/2;
	}
	return y;
}
//for thousand digit number
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
}
long long int power3(int *bi,int m,int x){
	long long int y=1,i=m-1;
	while(i>=0){
		if(bi[i]==1)
			y=y*x;
		x=x*x;
		i--;
	}	
	return y;
}
int main() {
	int x,n;
	cin>>x;
	cin>>n;
	cout<<power2(x,n);
	int s;
	cin >> s;
	int no[s];
	//to fill the array randomly
	for (int i = 0; i<s;++i){
		no[i]=rand()%10;
		cout<<no[i]<<' ';
	}
	cout<<'\n';
	int m=s*log2(10);
	int bi[m];
	decimaltobin(no,s,bi,m);
	cin>>x;
	cout<<power3(bi,m,x);
    return 0;
}