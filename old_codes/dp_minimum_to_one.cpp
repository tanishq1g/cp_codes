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
 //bottom to up dp works in large memory
int check[20000002];
int fun(long long n){
	if(check[n] != -1)
		return check[n];
	check[1] = 0;
	for(long long i = 2; i <= n; i++){
		check[i] = 1 + check[i-1];
		if(i%2 == 0)
			check[i] = min(check[i],1 + check[i/2]);
		if(i%3 == 0)
			check[i] = min(check[i],1 + check[i/3]);
	}
	
	return check[n];
}
 //top down dp gives stack memory error if large integers
int fun(long long n){
		if(check[n] != 0)
			return check[n];
		if(n == 1)
			return 0;
		//cout<<n<<' ';
		int r = 1 + fun( n - 1 );
		if( n%2 == 0 )   
			r  =  min( r , 1 + fun( n / 2 ) ) ;
		if( n%3 == 0 )   
			r  =  min( r , 1 + fun( n / 3 ) ) ;
		check[n] = r ;
}
int main(){
	long long n;
	int t,i=1;
	cin >> t;
	for(long long i = 0; i < 20000003; i++){
		check[i] = -1;
	}
	while(t--){
		cin >> n;
		if(n > 20000002){
			cout<<0<<'\n';
			continue;
		}
		cout<<"Case "<<i<<":"<<fun(n)<<'\n';
		i++;
	}
	
	return 0;
} 