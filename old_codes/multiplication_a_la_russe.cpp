#include <iostream>
using namespace std;

int main(){
	int a,b;
	cin>>a;
	cin>>b;
	int mul=0;
	if(a==1)
		mul+=b;
	else{

		while(a!=1){
			if(a%2==1){
				mul+=b;
			}
			a=a/2;
			b=2*b;
		}
		mul+=b;
	}
	cout<<mul;
	return 0;
}