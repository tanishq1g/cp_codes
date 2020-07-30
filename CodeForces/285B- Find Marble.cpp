#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;


int main(){
	int n,s,t;
	cin >> n;
	cin >> s;
	cin >> t;
	n++;
	int a[n];
	for(int i=1; i<n; i++){
		cin >> a[i];
	}
	int ctr = 0,i=s,c=0; 
	while(c<n){
		if(i == t){
			break; 
		}
		else{
			i = a[i];
			ctr++;
		}
		c++;
	}
	if ( s == t)
		cout << ctr;
	else if ( ctr == 0 || ctr > n-1)
		cout << "-1";
	else
		cout <<ctr;
}