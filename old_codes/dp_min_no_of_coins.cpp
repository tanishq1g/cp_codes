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
//minimum number of coins whose sum is s
int n,s;
int dp[52][123];
int c[52];
void min_coins_to_s(int s){
	memset(dp[0],0,sizeof dp[0]);
	dp[c[1]][0] = 0;
	for(int j=1; j<=s; j++){
		if(j - c[1] >= 0)
			dp[c[1]][j] = dp[c[1]][j - c[1]] + 1;
		else
			dp[c[1]][j] = 0;
	}
	for(int i=2; i<=n; i++){
		dp[c[i]][0] = 0;
		for(int j=1; j<=s; j++){
			dp[c[i]][j] = (j - c[i] >= 0 ? min(dp[c[i]][j-c[i]] + 1, dp[c[i-1]][j] + 1) : dp[c[i-1]][j]);
		}
	}
}

void to_find_which_coins(int s,int k){
	int i = k,j = s;
	int t = dp[c[i]][j];
	while(j != 0){
		if(i != 1){
			if(t == dp[c[i-1]][j]){
				i--;
			}
			else{
				j = j - c[i];
				t = dp[c[i]][j];
				cout<<"coin"<<c[i]<<'\n';
			}
		}
		else{
			cout<<"coin "<<c[0]<<'\n';
			j=0;
		}
	}
}
int main(){
	cin >> n >> s;
	for(int i=1; i<=n; i++){
		cin >>c[i];
	}
	sort(c,c+n+1);
	min_coins_to_s(s);
	for(int i=1; i<=n; i++){
		cout<<c[i] << " -";
		for(int j=0; j<=s; j++){
			cout<<dp[c[i]][j]<<' ';
		}
		cout<<'\n';
	}

	to_find_which_coins(11,2);
}
//LESS MEMORY
// int main(){
// 	int n;
// 	cin >> n ;
// 	int v[n];
// 	for(int i=0; i<n; i++){
// 		cin >> v[i];
// 	}
// 	int s;
// 	cin >> s;
// 	s++;
// 	int a[s];
// 	for(int i=1; i<s; i++){
// 		a[i] = INT_MAX;
// 	}
// 	a[0] = 0;
// 	for(int i=1; i<s; i++){
// 		for(int j=0; j<n; j++){
// 			if(v[j] <= i && a[i - v[j]] + 1< a[i])
// 				a[i] = a[i-v[j]]+1;
// 		}
// 	}
// 	for(int i=0; i<s; i++)cout<<a[i]<<' ';cout<<'\n';
// 	return 0;
// }