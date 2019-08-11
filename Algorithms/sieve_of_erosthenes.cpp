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