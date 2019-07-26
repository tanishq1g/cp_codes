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
#include <map>
using namespace std;
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define MOD 1000003;
struct plant{
	int c;
	float pc;
	float ho;
};
//dp for a person who is outside th grid and have to move through the grid to collect maximum coins
int main(){
	int n;
	cin >> n;
	int g[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> g[i][j];
		}
	}
	int dp[n][n];
	for(int i = 0; i < n; i++){
		dp[0][i] = g[0][i];
	}
	for(int i = 1; i < n; i++){
		dp[i][0] = max(g[i][0] + dp[i-1][0],g[i][0] + dp[i-1][1]);
		for(int j = 1; j < n-1; j++){
			dp[i][j] = max(max(g[i][j] + dp[i-1][j-1],g[i][j] + dp[i-1][j]),g[i][j] + dp[i-1][j+1]);
		}
		dp[i][n-1] = max(g[i][n-1] + dp[i-1][n-1],g[i][n-1] + dp[i-1][n-2]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << dp[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
// 2 people outside grid both have to take as many coins as possible while moving downwards and by never being at the same position 
int main(){
	int n;
	cin >> n;
	int g[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> g[i][j];
		}
	}
	int dp[n][n][n];	//coins collected by both whem they are at i row and at j1 and j2 index respectively 
	for(int j1 = 0; j1 < n; j1++){
		for(int j2 = 0; j2 < n; j2++){
			if(j1 == j2)
				dp[0][j1][j2] = 0;
			else
				dp[0][j1][j2] = g[0][j1] + g[0][j2];
		}
	}
	for(int i = 1; i < n; i++){
		for(int j1 = 0; j1 < n; j1++){
			for(int j2 = 0; j2 < n; j2++){
				if(j1 == j2){
					dp[i][j1][j2] = 0;
				}
				else if(j1 == 0 && j2 == 0){
					int max1 = INT_MIN,max2 = INT_MIN;
					for(int w1 = 0; w1 <= 1; w1++){
						for(int w2 = 0; w2 <= 1; w2++){
							if(j1 + w1 == j2 + w2);
							else{
								int c1 = g[i][j1] + dp[i-1][j1+w1][j2+w2] + g[i][j2];
								if(max1 < c1)
									max1 = c1;
							}
						}
					}
					dp[i][j1][j2] = max1;
				}
				else if(j1 == 0 && j2 == n-1){
					int max1 = INT_MIN,max2 = INT_MIN;
					for(int w1 = 0; w1 <= 1; w1++){
						for(int w2 = -1; w2 <= 0; w2++){
							if(j1 + w1 == j2 + w2);
							else{
								int c1 = g[i][j1] + dp[i-1][j1+w1][j2+w2] + g[i][j2];
								if(max1 < c1)
									max1 = c1;
							}
						}
					}
					dp[i][j1][j2] = max1;
				}
				else if(j1 == n-1 && j2 == 0){
					int max1 = INT_MIN,max2 = INT_MIN;
					for(int w1 = -1; w1 <= 0; w1++){
						for(int w2 = 0; w2 <= 1; w2++){
							if(j1 + w1 == j2 + w2);
							else{
								int c1 = g[i][j1] + dp[i-1][j1+w1][j2+w2] + g[i][j2];
								if(max1 < c1)
									max1 = c1;
							}
						}
					}
					dp[i][j1][j2] = max1;
				} 
				else if(j1 == n-1 && j2 == n-1){
					int max1 = INT_MIN,max2 = INT_MIN;
					for(int w1 = -1; w1 <= 0; w1++){
						for(int w2 = -1; w2 <= 0; w2++){
							if(j1 + w1 == j2 + w2);
							else{
								int c1 = g[i][j1] + dp[i-1][j1+w1][j2+w2] + g[i][j2];
								if(max1 < c1)
									max1 = c1;
							}
						}
					}
					dp[i][j1][j2] = max1;
				}
				else if(j1 == 0){
					int max1 = INT_MIN,max2 = INT_MIN;
					for(int w1 = 0; w1 <= 1; w1++){
						for(int w2 = -1; w2 <= 1; w2++){
							if(j1 + w1 == j2 + w2);
							else{
								int c1 = g[i][j1] + dp[i-1][j1+w1][j2+w2] + g[i][j2];
								if(max1 < c1)
									max1 = c1;
							}
						}
					}
					dp[i][j1][j2] = max1;
				}
				else if(j2 == 0){
					int max1 = INT_MIN,max2 = INT_MIN;
					for(int w1 = -1; w1 <= 1; w1++){
						for(int w2 = 0; w2 <= 1; w2++){
							if(j1 + w1 == j2 + w2);
							else{
								int c1 = g[i][j1] + dp[i-1][j1+w1][j2+w2] + g[i][j2];
								if(max1 < c1)
									max1 = c1;
							}
						}
					}
					dp[i][j1][j2] = max1;
				}
				else if(j1 == n-1){
					int max1 = INT_MIN,max2 = INT_MIN;
					for(int w1 = -1; w1 <= 0; w1++){
						for(int w2 = -1; w2 <= 1; w2++){
							if(j1 + w1 == j2 + w2);
							else{
								int c1 = g[i][j1] + dp[i-1][j1+w1][j2+w2] + g[i][j2];
								if(max1 < c1)
									max1 = c1;
							}
						}
					}
					dp[i][j1][j2] = max1;
				}
				else if(j2 == n-1){
					int max1 = INT_MIN,max2 = INT_MIN;
					for(int w1 = -1; w1 <= 1; w1++){
						for(int w2 = -1; w2 <= 0; w2++){
							if(j1 + w1 == j2 + w2);
							else{
								int c1 = g[i][j1] + dp[i-1][j1+w1][j2+w2] + g[i][j2];
								if(max1 < c1)
									max1 = c1;
							}
						}
					}
					dp[i][j1][j2] = max1;
				}
				else{
					int max1 = INT_MIN;
					for(int w1 = -1; w1 <= 1; w1++){
						for(int w2 = -1; w2 <= 1; w2++){
							if(j1 + w1 == j2 + w2);
							else{
								int c1 = g[i][j1] + dp[i-1][j1+w1][j2+w2] + g[i][j2];
								if(max1 < c1)
									max1 = c1;
							}
						}
					}
					dp[i][j1][j2] = max1;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j1 = 0; j1 < n; j1++){
			for(int j2 = 0; j2 < n; j2++){
				cout<<dp[i][j1][j2]<<" ";
			}
			cout<<'\n';
		}
		cout<<'\n';
	}
	return 0;
}