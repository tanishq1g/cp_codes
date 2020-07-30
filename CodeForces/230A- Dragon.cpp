#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;


bool cmp(vector<int> v1, vector<int> v2){
    return v1[0] < v2[0];
}

int main(){
    int s, n;
    cin >> s >> n;
    int x, y;
    vector<vector<int>> v(n, vector<int> (2, 0));
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v[i][0] = x;
        v[i][1] = y;
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++){
        if(s > v[i][0]){
            s += v[i][1];
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}