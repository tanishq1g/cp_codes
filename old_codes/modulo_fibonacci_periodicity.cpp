#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int modular(int m){
	int a=0,b=1,c=(a+b)%m,i,flag=0,h=2;
	for(i=2;i<(m*m);i++){
		
		a=b;
		b=c;
		c=(a+b)%m;
		if(b==0&&c==1){
			flag=1;
			break;
		}
		h++;
		
	}
	if(flag==1)
		return h;
	else return 0;
	
}

int main(){
	int m;
	cin>>m;
	int t= modular(m);
	if(t==0)
		cout<<"not periodic";
	else
		cout<<"is periodic-"<<t;	
}