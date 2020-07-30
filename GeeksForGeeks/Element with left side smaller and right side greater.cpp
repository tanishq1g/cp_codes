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

// array

// Function to return the index of the element which is greater than 
// all left elements and smaller than all right elements. 
int findElement(vector<int> arr, int n) 
{ 
    // leftMax[i] stores maximum of arr[0..i-1] 
    int leftMax[n]; 
    leftMax[0] = INT_MIN; 
  
    // Fill leftMax[]1..n-1] 
    for (int i = 1; i < n; i++) 
        leftMax[i] = max(leftMax[i-1], arr[i-1]); 
  
    // Initialize minimum from right 
    int rightMin[n];
    rightMin[n - 1] = INT_MAX; 

    for (int i = n - 2; i >= 0; i--) 
        rightMin[i] = min(rightMin[i + 1], arr[i + 1]); 

    // // Traverse array from right 
    for(int i = 1; i < n - 1; i++)
    { 
        // Check if we found a required element 
        cout << i  << ' ' << arr[i] << ' ' << leftMax[i] << ' ' << rightMin[i] << '\n';

        if (leftMax[i] <= arr[i] && rightMin[i] >= arr[i]) 
             return arr[i]; 
    } 
  
    // If there was no element matching criteria 
    return -1; 
} 

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ve(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];
        }
        cout << findElement(ve, n) << '\n';
    }
    return 0;
}
