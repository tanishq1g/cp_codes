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
int dp[4005],vs[4005];
int n,r[3],size;
int max_piecesof_ribbon_to_n(int n){
	cout<<n<<' ';
	
	if(n == 0){
		return 0;
	}
	if(n < 0)
		return -40000;
	if(vs[n] != 0)
		return dp[n];
	for(int i = 0; i < size; i++){
			vs[n] = 1;
			dp[n] = max(max_piecesof_ribbon_to_n(n - r[i]) + 1,dp[n]);
			// if (n - r[i] < 0){
			// 	break;
			// }
	}
	return dp[n];
}
int main(){
	cin >> n >> r[0] >> r[1] >> r[2];
	sort(r,r+3);
	size = 0;
	r[size] = r[0];
	size++;
	for(int i = 1; i < 3; i++){
		if(r[size-1] != r[i]){
			r[size] = r[i];
			size++;
		}
	}
	if(size == 1){
		cout<<n/r[0];
	}
	else{
		cout<<max_piecesof_ribbon_to_n(n)<<"sd\n";
		for(int i = 0; i <= n; i++){
			cout<<i<<"/"<<dp[i]<<' ';
		}
	}
	return 0;
} 


// #include <iostream>
// using namespace std;
// int a,b,c,n,m=1,t,d;
// main()
// {
// 	cin>>n>>a>>b>>c;
// 	for(int i=0;i<=4000;++i)
// 		for(int j=0;j<=4000;++j){
// 			t = n - a*i - b*j;
// 			if(t >= 0 && t%c ==0)
// 				m = max(m,i+j+t/c);
// 		}
// 	cout<<m;
// }