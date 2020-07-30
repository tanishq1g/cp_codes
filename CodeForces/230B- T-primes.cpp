#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;

vector<int> sieve(long long int n){
    vector<bool> prime(n, true);
    vector<int> ret;
    for(long long int i = 2; i < n; i++){
        if(prime[i] && i * i < n){
            ret.push_back(i);
            // cout << i << ' ';
            for(long long int j = i * i; j < n; j += i){
                prime[j] = false;
            }
        }
    }
    for(int i = ret[ret.size() - 1] + 1; i < n; i++){
        if(prime[i]){
            // cout << i << ' ';
            ret.push_back(i);
        }
    }
    return ret;
}

int main(){
    vector<int> prime = sieve(1000000);
    long long int n, x;
    cin >> n;
    double s;
    for(int i = 0; i < n; i++){
        cin >> x;
        s = sqrt(x);
        if(s - floor(s) == 0 && binary_search(prime.begin(), prime.end(), s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}