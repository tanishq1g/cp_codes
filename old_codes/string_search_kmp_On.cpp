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
//In the preprocessing part, we calculate values in lps[]. To do that, we keep track of the length of the longest prefix suffix value (we use len variable for this purpose) for the previous index. We initialize lps[0] and len as 0. If pat[len] and pat[i] match, we increment len by 1 and assign the incremented value to lps[i]. If pat[i] and pat[len] do not match and len is not 0, we update len to lps[len-1]. See computeLPSArray () in the below code for details.


void computelps(string &pat,int lpat,string &lps){
	int len = 0;
	int i = 1;
	lps[0] = 0;
	while( i < lpat){
		if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len != 0){
				len = lps[len - 1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}
// //How to use lps[] to decide next positions (or to know number of characters to be skipped)?

// We start comparison of pat[j] with j = 0 with characters of current window of text.
// We keep matching characters txt[i] and pat[j] and keep incrementing i and j while pat[j] and txt[i] keep matching.
// When we see a mismatch
// We know that characters pat[0..j-1] match with txt[i-j+1…i-1] (Note that j starts with 0 and increment it only when there is a match).
// We also know (from above definition) that lps[j-1] is count of characters of pat[0…j-1] that are both proper prefix and suffix.
// From above two points, we can conclude that we do not need to match these lps[j-1] characters with txt[i-j…i-1] because we know that these characters will anyway match. Let us consider above example to understand this.
void KMPsearch(string &txt,string &pat){
	int lpat = pat.length();
	int ltxt = txt.length();
	string lps;
	computelps(pat,lpat,lps);
	for(int i=0; i<lpat; i++)cout<<lps[i]<<' ';cout<<'\n';
	int i = 0, j = 0;
	while(i < ltxt){
		if(pat[j] == txt[i]){
			i++;
			j++;
		}
		if(j == lpat){
			cout<<"pattern at index "<<i-j<<'\n';
			j = lps[j - 1];
		}
		else if(i < ltxt && pat[j] != txt[i]){
			if(j != 0)
				j = lps[j-1];
			else
				i = i + 1;
		}

	}
}
int main(){
	string a = "ABABDABACDABABCABAB";
	string b = "AB";
	KMPsearch(a,b);
}