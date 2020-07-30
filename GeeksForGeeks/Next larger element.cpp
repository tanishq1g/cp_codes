#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// STACK AND HEAPS


int main()
{
	int t, n;
	cin >> t;
	while(t--) {
	    cin >> n;
	    vector <long long int> arr(n), ans(n);
	    
	    for(int i = 0; i < n; i++)
	        cin >> arr[i];
	    stack <long long int> s;
	    for(int i = n-1; i >= 0; i--) {
	        while(!s.empty() && arr[i] >= s.top())
	            s.pop();
	        ans[i] = s.empty() ? -1 : s.top();
	        s.push(arr[i]);
	    }
	    
	    for(int i = 0; i < n; i++)
	        cout << ans[i] << " ";
	    cout << endl;
	}
	return 0;
}