#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    vector<int> v1,v2,v3;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 1)
            v1.push_back(i + 1);
        else if(x == 2)
            v2.push_back(i + 1);   
        else if(x == 3)
            v3.push_back(i + 1);
    }
    int l1 = v1.size();
    int l2 = v2.size();
    int l3 = v3.size();
    if(l1 == 0 || l2 == 0 || l3 == 0){
        cout << 0; return 0;
    }
    int l = min(l1, min(l2, l3));
    cout << l << endl;
    for(int i = 0; i < l; i++){
        cout << v1[i]<< ' '<< v2[i]<< ' '<< v3[i]<< endl;
    }
    return 0;
}