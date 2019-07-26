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
int dp[2003][2003];
int agnes[2003];
int tom[2003];
int n1,n2;
int dp_lcs(){
	for(int i = 1; i < n1; i++){
		for(int j = 1; j < n2; j++){
			if(agnes[i] == tom[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	// for(int i = 0; i < n1; i++){
	// 	for(int j = 0; j < n2; j++){
	// 		cout << dp[i][j]<<' ';
	// 	}
	// 	cout<<'\n';
	// }
	return dp[n1-1][n2-1];
}
int main(){
	int t;
	cin >> t;
	for(int i = 0; i < 2003; i++){
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	while(t--){
		int max = 0;
		int a;
		cin >> a;
		n1 = 1;
		while(a != 0){
			agnes[n1] = a;
			n1++;
			cin >> a;
		}
		while(1){
			cin >> a;
			if(a == 0)
				break;
			n2 = 1;
			while( a != 0){
				tom[n2] = a;
				n2++;
				cin >> a;
			}
			int ans = dp_lcs();
			if(ans > max){
				max = ans;
			}
			//cout<<ans<<' '<<max<<'\n';
		}
		cout<<max<<'\n';
	}
	return 0;
} 

