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
#include <stack>
using namespace std;
#define MOD 1000000007
//dp[i][j] stores len of lcs till i,j
int main(){
	int n,m;
	cin >> n >> m;
	n++;m++;
	int a[n],b[m];
	for(int i = 1; i < n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < m; i++){
		cin >> b[i];
	}

	int dp[n][m]; 	//stores the length of largest lcs at each point
	for(int i = 0; i <m; i++){
		dp[0][i] = 0;
	}
	for(int i = 0; i < n; i++){
		dp[i][0] = 0;
	}
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(a[i] == b[j]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		cout << dp[i][j]<<' ';
	// 	}
	// 	cout<<'\n';
	// }

	stack <int> s;
	int i = n-1,j = m-1;
	while(dp[i][j] != 0){
		//cout<<i<<' '<<j<<'\n';
		if(a[i] == b[j]){
			s.push(a[i]);
			i--;
			j--;
		}
		else if(dp[i][j] == dp[i-1][j]){
			i--;
		}
		else{
			j--;
		}

	}
	while(!s.empty()){
		cout<<s.top()<<' ';
		s.pop();
	}
	return 0;
} 