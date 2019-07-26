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

void matrix_power_naive(int n,int m,int a[][m],int result [n][m]){
	memset(result,1,sizeof result);
	int sum;
	for(int w=0; w<n; w++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){

			}
		}
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	int a[n][m],result[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
		}
	}
	return 0;
}