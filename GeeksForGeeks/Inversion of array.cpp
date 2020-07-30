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


long long int merge(vector<int> &ve, int l, int r, int mid){
    long long int c = 0;
    int n1 = mid - l + 1, n2 = r - mid;
    vector<int> v1(n1), v2(n2);
    for(int i = 0; i < n1; i++){
        v1[i] = ve[l + i];
    }
    for(int i = 0; i < n2; i++){
        v2[i] = ve[mid + 1 + i];
    }
    
    int k = l;
    // cout << l << ' ' << mid << ' ' << r << ' ' << c << '\n';

    for(int i = 0, j = 0; ;){
        if(i == n1){
            while(j < n2){
                ve[k] = v2[j];
                j++;k++;
            }
            break;
        }
        if(j == n2){
            while(i < n1){
                ve[k] = v1[i];
                i++;k++;
            }
            break;
        }
        if(v1[i] <= v2[j]){
            ve[k] = v1[i];
            i++;
        }
        else{
            ve[k] = v2[j];
            j++;
            c += n1 - i;
        }
        k++;
    }
    // cout << l << ' ' << mid << ' ' << r << ' ' << c << '\n';
    return c;
}

long long int mergesort(vector<int> &ve, int l, int r){
    // cout << l << ' ' << r << '\n';
    long long int c = 0;
    if(l >= r){
        return 0;
    }
    int mid = (l + r) / 2;
    c += mergesort(ve, l, mid);
    // cout << "v1 " << l << ' ' <<  r << ' ' << c << '\n';
    c += mergesort(ve, mid + 1, r);
    // cout << "v2 " << l << ' ' <<  r << ' ' << c << '\n';
    c += merge(ve, l, r, mid);
    // cout << "v3 " << l << ' ' <<  r << ' ' << c << '\n';
    return c;
}

int main(){
    int t;
    cin >> t;
    long long int c;
    while(t--){
        int n;
        cin >> n;
        vector<int> ve(n);
        for(int i = 0; i < n; i++){
            cin >> ve[i];   
        }
        c = 0;
        c = mergesort(ve, 0, n - 1);
        for(int i = 0; i < n; i++){
            cout << ve[i] << ' ';
        } cout << endl;
        cout << c << '\n';
    }
    return 0;
}