#include <iostream>

#include <cstdlib>
#include <cmath>

using namespace std;
int main(){

	int s;
	cin >> s;
	int no[s];
	//to fill the array randomly
	for (int i = 0; i<s;++i){
		no[i]=rand()%10;
		cout<<no[i]<<' ';
	}
	cout<<'\n';
	int m=s*log2(10);
	cout<<m<<'\n';
	int bi[m];
	int che=s-1;
	int k=m-1;
	for(int j=0;j<s-1;){
		bi[k--]=no[che]%2;
		for(int i=j;i<s;i++){
			no[i+1]+=(no[i]%2)*10;
			no[i]=no[i]/2;
		}
		if(no[j]==0){
			j++;
		}
	}
	while(no[che]!=1){
		bi[k--]=no[che]%2;
		no[che]=no[che]/2;
	}
	bi[k--]=no[che]%2;
	
		cout<<'\n';
		for (int i = 0; i<s;++i){
			cout<<no[i]<<".. ";
		}
		cout<<'\n';
	
	cout<<'\n';
	for (int k = 0; k < m; ++k){
		cout<<bi[k]<<' ';
	}
	cout<<'\n';
	return 0;
}