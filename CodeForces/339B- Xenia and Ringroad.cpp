#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m;
    m++;
    int curr = 1;
    long long int tot = 0;
    for(int i = 1; i < m; i++){
        cin >> x;
        if(x >= curr){
            tot += x - curr;
            curr = x;
        }
        else{
            tot += n - curr + 1 + x - 1;
            curr = x;
        }
        // cout << curr<< ' ' << tot<<endl;
    }
    cout << tot;
    return 0;
}