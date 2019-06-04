//#include <cmath>
#include <cstdio>
//#include <vector>
#include <iostream>
//#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int q;
	cin >> q;
	int t;
	string name;
	int marks;
	std::map<string, int> m;
	// cin >> name >>  marks;
	// m[name] += marks;
	// cout << m[name];
	// cin >> name >>  marks;
	// m.insert(make_pair(name, marks));
	// cout << m[name];

	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> name >> marks;
			m[name] += marks;
			cout << "sdsd"<<m[name]<<'\n';
			// if(!m[name]){
			// 	cout<<"in  ";
			// 	m.insert(make_pair(name, marks));
			// 	cout<<m[name]<<'\n';
			// }
			// else{
			// 	m[name] += marks;
			// 	cout<<m[name]<<'\n';
			// }
		}
		else if (t == 2) {
			cin >> name;
			m.erase(name);
		}
		else {
			cin >> name;
			cout << m[name]<<'\n';
		}
	}
	return 0;
}
