#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

const int MAXS = 1000;
const int MAXC = 26;
int g[MAXS][MAXC];
int fail[MAXS];
int out[MAXS];
int currentstate,states;

void preapretrie(){
	states = 1;
	memset(out, 0 , sizeof out);
	memset(fail, -1, sizeof fail);
	memset(g, -1, sizeof g);
}

void insertstr_ahoi(string str,int index){
	int n = str.length(),c;
	currentstate = 0;
	for(int i=0; i<n; i++){
		c = str[i] - 97;
		if(g[currentstate][c] == -1){
			g[currentstate][c] = states++;
		}
		currentstate = g[currentstate][c];
	}
	out[currentstate] |= (1 << index);
}

void createfail_ahoi(){
	for(int i=0; i<MAXC; i++){
		if(g[0][i] == -1)
			g[0][i] = 0;
	}

	queue <int> q;
	for(int i=0; i<MAXC; i++){
		if(g[0][i] != -1 and g[0][i] != 0){
			fail[g[0][i]] = 0;
			q.push(g[0][i]);
		}
	}

	while(q.size()){
		int state = q.front();
		q.pop();
		for(int i=0; i<MAXC; i++){
			if(g[state][i] != -1){
				int failure = fail[state];
				while(g[failure][i] == -1){
					failure = fail[failure];
				}
				failure = g[failure][i];
				fail[g[state][i]] = failure;
				out[g[state][i]] |= out[failure];
				q.push(g[state][i]);
			}
		}
	}
}

int nextstate(int currentstate,char ch){
	int answer = currentstate;
	int c = ch - 97;
	while(g[answer][c] == -1){
		answer = fail[answer];
	}
	return g[answer][c];
}


int main(){
	int n;
	cin >> n;
	string str[n];
	preapretrie();
	for(int i=0; i<n; i++){
		cin >> str[i];
		insertstr_ahoi(str[i],i);
	}
	
	createfail_ahoi();

	for(int i=0; i<10; i++){
        cout << out[i] << ' ';
    }
    cout<<endl;
    for(int i=0; i<10; i++){
        cout << fail[i] << ' ';
    }
    cout<<endl;
	string text;
	cin >>text;



	int currentstate = 0;
	for(int i=0; i<text.length(); i++){
		currentstate = nextstate(currentstate,text[i]);
		if(out[currentstate] == 0)
			continue;
		for(int j=0; j<n; j++){
			if(out[currentstate] & (1 << j)){
				cout << str[j] << ' ' << i - str[j].length() + 1<<' '<<currentstate<<' '<<i<<endl;
			}
		}
	}
	return 0;
}