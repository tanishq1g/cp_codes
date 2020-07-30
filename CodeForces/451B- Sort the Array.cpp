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
    int l, r;
    int i = 0;
    while(i + 1 < n && ve[i] < ve[i + 1]){
        i++;
    }
    if(i == n - 1){
        cout << "yes\n";
        cout << 1 << ' ' << 1;
        return 0;
    }

    int ie = i;
    l = i;
    // cout << ie << ' ' << i << '\n';
    while(i + 1 < n && ve[i] > ve[i + 1]){
        i++;
    }
    r = i;
    // cout << r << '\n';
    
    if(r == n - 1){
        if(ie == 0){
            cout << "yes"<<endl;
            cout << l + 1 << ' ' << r + 1;
        }
        else if(ve[ie - 1] < ve[r]){
            cout << "yes"<<endl;
            cout << l + 1 << ' ' << r + 1;
        }
        else{
            cout << "no";
        }
        return 0;
    }
    
    while(i + 1 < n && ve[i] < ve[i + 1]){
        i++;
    }
    // cout << i << '\n';
    if(i == n - 1){
        if(ie == 0 && ve[l] < ve[r + 1]){
            cout << "yes"<<endl;
            cout << l + 1 << ' ' << r + 1;
        }
        else if(ve[ie - 1] < ve[r] && ve[l] < ve[r + 1]){
            cout << "yes"<<endl;
            cout << l + 1 << ' ' << r + 1;
        }
        else
            cout << "no";
        return 0;
    }
    cout << "no";
    return 0;
}