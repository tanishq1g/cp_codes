#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;


int rec(int n){
	if(n<2&&n>=0)
		return n;
	else
		return(rec(n-1)+rec(n-2))%100;
}
int main() {
    
	int n;
	cin>>n;
	clock_t start=clock();
	cout<<rec(n-1);
	clock_t stop=clock();
	cout<<'\n'<<"time taken-"<<double(stop-start)/ CLOCKS_PER_SEC;
    return 0;
}	
