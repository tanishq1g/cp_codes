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

void stockBuySell(vector<int> price, int n) 
{ 
    // Prices must be given for at least two days 
    if (n == 1) 
        return; 
  
    // Traverse through given price array 
    int i = 0; 
    while (i < n - 1) { 
  
        // Find Local Minima 
        // Note that the limit is (n-2) as we are 
        // comparing present element to the next element 
        while ((i < n - 1) && (price[i + 1] <= price[i])) 
            i++; 
  
        // If we reached the end, break 
        // as no further solution possible 
        if (i == n - 1) 
            break; 
  
        // Store the index of minima 
        int buy = i++; 
  
        // Find Local Maxima 
        // Note that the limit is (n-1) as we are 
        // comparing to previous element 
        while ((i < n) && (price[i] >= price[i - 1])) 
            i++; 
  
        // Store the index of maxima 
        int sell = i - 1; 
  
        cout << "(" << buy <<' ' << sell << ") ";
    } 
    cout << '\n';
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
        int mi = -1;
        int i = 0;
        while(i < n - 1){
            if(ve[i] < ve[i + 1]){
                mi = i;
                break;
            }
            i++;
        }  
        if(mi == -1){
            cout << "No Profit\n";
            continue;
        }
        stockBuySell(ve, n);
        // int st = 0, ma, maind;
        // i++;
        
        // while(i < n){
        //     ma = INT_MIN;
        //     while(ve[i] >= ve[mi] && i < n){
        //         if(ma <= ve[i]){
        //             ma = ve[i];
        //             maind = i;
        //         }
        //         i++;
        //     }
        //     st += ma - ve[mi];
        //     cout << '(' << mi << ' ' << maind << ") ";
        //     mi = i;
        //     i++;
        // }
        // cout << endl;
    }
    return 0;
}
