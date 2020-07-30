#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ve(n);
    for(int i = 0; i < n; i++){
        cin >> ve[i];   
    }
    int i = 0;
    while(i + 1< n && ve[i] <= ve[i + 1]){
        i++;
    }
    if(i == n - 1){
        cout << 0;
        return 0;
    }
    else{
        int k = i;
        i++;
        while(i + 1< n && ve[i] <= ve[i + 1]){
            i++;
        }
        // cout << k << ' ' << i << '\n';
        if(i == n - 1){
            if(ve[0] >= ve[i])
                cout << n - k - 1;
            else
                cout << -1;
            return 0;
        }
    }
    i = 0;
    while(i + 1 < n && ve[i] >= ve[i + 1]){
        i++;
    }
    if(i == n - 1){
        if(n == 2)
            cout << n - 1;
        else    
            cout << -1;
        return 0;
    }
    // else{
    //     int k = i;
    //     i++;
    //     while(i + 1 < n && ve[i] >= ve[i + 1]){
    //         i++;
    //     }
    //     // cout << k << ' ' << i << '\n';
    //     if(i == n - 1){
    //         if(ve[0] <= ve[i])
    //             cout << n - k - 1 + n - 1;
    //         else
    //             cout << -1;
    //         return 0;
    //     }
    // }
    cout << -1;
    return 0;
}