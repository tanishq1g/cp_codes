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
#include <stack>
#include <iomanip>
#include <climits>
using namespace std;



string addintto_string(string s,int t){
	int l = s.length();
	int no;
	for(int i=l-1; i>=0; i--){
		no = s[i] - 48 + t;
		if(no > 9){
			s[i] = no%10 + 48;
			t = no/10;
			if(i == 0)
				s = to_string(t) + s ;
		}
		else{
			s[i] = no + 48;
			break;
		}
	}
	return s;
}
int main(){
	string s = "999";
	int a = 1;
	cout<<addintto_string(s,a);
}