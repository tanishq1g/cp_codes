#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    vector<int> pi(n, 0);
    for(int i = 0; i < n; i++){
        cin >> x;
        pi[x - 1] = i + 1;
    }
    for(vector<int>::iterator it = pi.begin(); it != pi.end(); it++){
        cout<<*it<<' ';
    }
    return 0;
}