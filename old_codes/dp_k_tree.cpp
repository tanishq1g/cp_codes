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
#define mod 1000000007
using namespace std;
int dp[101][2];
void add(int &a, int b)
{
    a += b;
    if(a >= mod)
        a -= mod;
}


int main(){
	int n,k,d;
	cin >> n >> k >> d;

	dp[0][0] = 1;
	dp[0][1] = 0;

	for(int i = 1; i <= n; i++){
		dp[i][0] = 0;
		dp[i][1] = 0;
		for(int j = 1; j <= min(d-1,i); j++){
			dp[i][0] += dp[i-j][0];
			dp[i][1] += dp[i-j][1]; 
			if(dp[i][0] >=mod)
				dp[i][0] -= mod;
			if(dp[i][1] >=mod)
				dp[i][1] -= mod;
		}
		for(int j = d; j <= min(i,k); j++){
			dp[i][1] += dp[i-j][0];
			if(dp[i][1] >=mod)
				dp[i][1] -= mod;
			dp[i][1] += dp[i-j][1];
			if(dp[i][1] >=mod)
				dp[i][1] -= mod;
		}
	}
	for(int i = 0; i <= n; i++){
		cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<'\n';
	}
	cout<<dp[n][1]<<'\n';
//alternate code
	dp[0][0] = 1;
    dp[0][1] = 0;
    
    for(int i = 1 ; i <= n ; ++i)
    {
        dp[i][0] = dp[i][1] = 0;
        
        for(int j = 1 ; j <= k ; ++j)
        {
            if(i-j < 0) break;
            
            if(j < d)
            {
                add(dp[i][0], dp[i-j][0]);
                add(dp[i][1], dp[i-j][1]);
            }
            else
            {
                add(dp[i][1], dp[i-j][0]);
                add(dp[i][1], dp[i-j][1]);
            }
        }
    }
    
	for(int i = 0; i <= n; i++){
		cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<'\n';
	}
	cout << dp[n][1] << "\n";
	return 0;
}