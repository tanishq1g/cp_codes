#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
using namespace std;

// dynamic_programming
int deno[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000}; 
int n = sizeof(deno) / sizeof(deno[0]); 

void findMin(int V) 
{ 
	sort(deno, deno + n); 

	// Initialize result 
	vector<int> ans; 

	// Traverse through all denomination 
	for (int i = n - 1; i >= 0; i--) { 

		// Find denominations 
		while (V >= deno[i]) { 
			V -= deno[i]; 
			ans.push_back(deno[i]); 
		} 
	} 

	// Print result 
	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i] << " "; 
    cout << endl;
} 

int main(){
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        findMin(m);
    }
    return 0;
}