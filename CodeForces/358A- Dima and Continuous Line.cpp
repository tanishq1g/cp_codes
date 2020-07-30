#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    if(v1[0] == v2[0])
        return v1[1] < v2[1];
    return v1[0] < v2[0];
}
int main(){
    int n, x, y;
    cin >> n;
    vector<vector<int>> ve(n - 1, vector<int>(2));
    cin >> x;
    if(n == 1){
        cout << "no";
        return 0;
    }
    for(int i = 1; i < n; i++){
        cin >> y;
        ve[i - 1][0] = min(x, y);
        ve[i - 1][1] = max(x, y);
        x = y;
    }
    sort(ve.begin(), ve.end(), cmp);
    n--;
    int k = 1;
    for(int i = 1; i < n; i++){
        k = 1;
        while(i - k >= 0){
        // cout << ve[i][0] << ' '<<ve[i][1]<<endl;
            if(ve[i][0] != ve[i - k][0] && ve[i][0] < ve[i - k][1] && ve[i][1] > ve[i - k][1]){
                cout << "yes";
                return 0;
            }
            // if(ve[i][0] != ve[i - k][0])
            //     break;
            k++;
        }
        // cout << endl;
    }
    cout << "no";
    return 0;
}