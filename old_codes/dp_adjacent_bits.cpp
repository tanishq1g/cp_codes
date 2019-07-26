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
using namespace std;
//ques
// For a string of n bits x1,x2,x3,...,Xn the adjacent bit count of the string (AdjBC(x)) is given by


// X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn


// which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
// AdjBC(011101101) = 3
// AdjBC(111101101) = 4
// AdjBC(010101010) = 0

// Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2ⁿ) that satisfy AdjBC(x) = k. For example, for 5 bit strings, there are 6 ways of getting AdjBC(x) = 2:
// 11100, 01110, 00111, 10111, 11101, 11011

// at each iteration (so for numbers of a given length n), keep a list of all the states so far, and for each state, in how many ways that state could have been reached:

// struct State
// {
// int numAdjOnes;
// int prevBit;
// int numWays;
// };

// Then using that information, it's should be pretty straightforward to calculate the new state information, for numbers of length n + 1

// Then you just repeat this process until you have your information for numbers of the length you needed, and then you select the two states with the correct number of adjacent ones, where on of them will have prevBit to 1, and another one prevBit to 0. Then you add their numWays, which will be your answer.
// long long int dp[105][100][2];

int main(){
	int t;
	cin>>t;
	for(int i=0;i<100;++i){
		dp[0][i][0]=dp[0][i][1]=0;
	}
	dp[1][0][1]=dp[1][0][0]=1;
	for(int n=2;n<105;++n){
		dp[n][0][0]=dp[n-1][0][1]+dp[n-1][0][0];
		dp[n][0][1] = dp[n-1][0][0];
	}
	for(int n=1;n<105;n++){
		for(int k=1;k<100;++k){
			dp[n][k][1]= dp[n-1][k][0]+dp[n-1][k-1][1];
			dp[n][k][0] = dp[n-1][k][0]+dp[n-1][k][1];
		}
	}
	while(t--){
		int r;
		cin>>r;
		int n,k;
		cin>>n>>k;
		cout<<r<<" "<<dp[n][k][0]+dp[n][k][1]<<endl;
	}
}

