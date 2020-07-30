#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
#include <climits>
using namespace std;

// dynamic_programming

bool cmp(vector<int> &v1, vector<int> &v2){
    if(v1[0] > v2[0]){
        return true;
    }
    else if(v1[0] == v2[0]){
        if(v1[1] > v2[1]){
            return true;
        }
        else if(v1[1] == v2[1]){
            if(v1[2] >= v2[2]){
                return true;
            }
            return false;
        }   
        return false;
    }
    return false;
}
int maxHeight(int h[],int w[],int l[],int n){
    int m = 3*n;
    vector<vector<int> > ve(m, vector<int> (3));
    for(int i = 0, j = 0; i < n; i++){
        ve[j][0] = l[i];
        ve[j][1] = w[i];
        ve[j][2] = h[i];
        sort(ve[j].begin(), ve[j].end(), greater<int>());
        j++;
        ve[j][0] = ve[j - 1][0];
        ve[j][1] = ve[j - 1][2];
        ve[j][2] = ve[j - 1][1];
        j++;
        ve[j][0] = ve[j - 2][1];
        ve[j][1] = ve[j - 2][2];
        ve[j][2] = ve[j - 2][0];
        j++;
    }

    sort(ve.begin(), ve.end(), cmp);
    for(int j = 0; j < m; j++){
        cout << j << " - " << ve[j][0] << ' ' << ve[j][1] << ' ' << ve[j][2] << '\n';  
    }
    int su = ve[0][2], la = 0;
    for(int i = 1; i < m; i++){
        for(int j = la; j < i; j++){
            if(ve[j][0] > ve[i][0] && ve[j][1] > ve[i][1]){
                su += ve[i][2];
                la = i;
                // cout << i << ' ' << j << ' ' << la << ' ' << su << endl;
                break;
            }
        }
    }
    return su;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[1000], b[1000], c[1000];
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i] >> c[i];   
        }
        cout << maxHeight(a, b, c, n) << endl;
    }
    return 0;
}