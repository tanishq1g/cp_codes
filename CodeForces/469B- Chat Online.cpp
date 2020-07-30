#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;
vector<bool> li(1001, false);

int main(){
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    vector<int> px(p), py(p);
    for(int i = 0; i < p; i++){
        cin >> px[i] >> py[i];
    }
    int x, y, d1, d2;
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        for(int j = 0; j < p; j++){
            d1 = px[j] - y;
            d2 = py[j] - x;
            // cout << i << ' ' << d1 <<' ' <<  d2 << '\n';
            for(int k = max(d1, l); k <= d2 && k <= r; k++){
                li[k] = true;
            }
        }
    }
    int c = 0;
    for(int i = l; i <= r; i++){
        if(li[i])
            c++;
    }
    cout << c;
    return 0;
}