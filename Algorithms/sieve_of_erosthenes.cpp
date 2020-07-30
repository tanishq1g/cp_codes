#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>

using namespace std;

void sieve(int n){
    vector<bool> prime(n, true);
    for (int i = 2; i*i < n; i++){
        if(prime[i]){
            cout<<"i  "<<i<<'\n';
            for (int j = i*i; j < n; j+=i){
                cout<<j<<'\n';
                prime[j] = false;
            }
        }
    }
    int c=0;
    for (int i = 2; i < n; i++)
    {
        if(prime[i]){
            c++;
        }
    }
}


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
    cout << ret[ret.size() - 1] + 1 << '\n';
    for(int i = ret[ret.size() - 1] + 1; i < n; i++){
        if(prime[i]){
            // cout << i << ' ';
            ret.push_back(i);
        }
    }
    return ret;
}