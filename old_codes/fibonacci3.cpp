#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;


int main() {
    
	int a,b,c,n;
	cin>>n;
	clock_t start=clock();
	a=0;
	b=1;
	c=(a+b)%100;
	for (int i = 2; i < n; ++i)
	{
		a=b;
		b=c;
		c=(a+b)%100;
	}
	cout<<"ans-"<<c;
	clock_t stop=clock();
	cout<<'\n'<<"time taken-"<<double(stop-start)/ CLOCKS_PER_SEC;
    return 0;
}	