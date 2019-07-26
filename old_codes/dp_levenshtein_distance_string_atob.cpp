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
//dp[i][j] stores no of operations done till i,j
int dp[2003][2003];
int lavenshtein_distance_recursuve(string & a,int lena,string &b,int lenb){
	if(lena == 0)
		return lenb;
	if(lenb == 0)
		return lena;
	int cost;
	if(a[lena - 1] == b[lenb - 1])
		cost = 0;
	else
		cost = 1;
	return min(min(lavenshtein_distance_recursuve(a,lena - 1,b,lenb) + 1, lavenshtein_distance_recursuve(a,lena,b,lenb - 1) + 1), lavenshtein_distance_recursuve(a,lena - 1,b,lenb - 1) + cost);
}	

int lavenshtein_distance_dp(string & a,int lena,string &b,int lenb){
	for(int i = 0; i < lena+1; i++){
		for(int j = 0; j < lenb+1; j++){
			if(i == 0 || j == 0){
				dp[i][j] = max(i,j);
			}
			else{
				int cost;
				if(a[i - 1] == b[j - 1])
					cost = 0;
				else
					cost = 1;
				dp[i][j] = min(min(dp[i-1][j] + 1,dp[i][j-1] + 1),dp[i-1][j-1] + cost);
			}
		}
	}
	return dp[lena][lenb];
}
int main(){
	string a,b;
	cin >> a >> b;
	cout<<lavenshtein_distance_dp(a,a.length(),b,b.length());
	return 0;
} 

