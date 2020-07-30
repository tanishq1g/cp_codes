#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <queue>
#include <stack>
using namespace std;

// GRAPH

int minSwaps(int arr[], int N){
    vector<bool> vis(N, false);
    int count  = 0, gctr, k;
    
    for(int i = 0; i < N; i++){
        gctr = 0;
        if(vis[i] == false && arr[i] != i + 1){
            k = arr[i];
            // gctr++;
            while(vis[k - 1] != true){
                vis[k - 1] = true;
                k = arr[k - 1];
                gctr++;
            }
            count += gctr - 1;
        }    
        else if(arr[i] != i + 1){
            vis[i] = true;
        }
    }

    return count;
}
