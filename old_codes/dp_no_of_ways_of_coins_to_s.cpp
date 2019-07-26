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
void no_of_sets_to_s(int s){
	memset(dp[0],0,sizeof dp[0]);
	dp[c[1]][0] = 1;
	for(int j=1; j<=s; j++){
		if(j - c[1] >= 0)
			dp[c[1]][j] = dp[c[1]][j - c[1]];
		else
			dp[c[1]][j] = 0;
	}
	for(int i=2; i<=n; i++){
		dp[c[i]][0] = 1;
		for(int j=1; j<=s; j++){
			dp[c[i]][j] = (j - c[i] >= 0 ? dp[c[i]][j-c[i]] + dp[c[i-1]][j] : dp[c[i-1]][j]);
		}
	}
}

int main(){
	cin >> n >> s;
	for(int i=1; i<=n; i++){
		cin >>c[i];
	}
	sort(c,c+n+1);
	no_of_sets_to_s(s);
	for(int i=1; i<=n; i++){
		cout<<c[i] << " -";
		for(int j=0; j<=s; j++){
			cout<<dp[c[i]][j]<<' ';
		}
		cout<<'\n';
	}

}
