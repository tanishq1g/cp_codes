#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;


int main() {
    
	int n;
	cin>>n;
	clock_t start=clock();
	int f[n];
	f[0]=0;
	f[1]=1;
	for (int i = 2; i < n; ++i)
	{
		f[i]=(f[i-1]+f[i-2])%100;
	}
	cout<<"ans-"<<f[n-1];
	clock_t stop=clock();
	cout<<'\n'<<"time taken-"<<double(stop-start)/ CLOCKS_PER_SEC;
    return 0;
}	