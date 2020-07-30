#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmpx(vector<int> v1, vector<int> v2){
    if(v1[0] == v2[0]){
        return v1[1] < v2[1];
    }
    return v1[0] < v2[0];
}
bool cmpy(vector<int> v1, vector<int> v2){
    if(v1[1] == v2[1]){
        return v1[0] < v2[0];
    }
    return v1[1] < v2[1];
}

int main(){
    int n;
    cin >> n;
    int x, y;
    vector<vector<int>> vx(n, vector<int>(3)); 
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        vx[i][0] = x;
        vx[i][1] = y;
        vx[i][2] = i;
    }
    vector<vector<int>> vy(vx.begin(), vx.end());
    vector<int> vch(n, 0);
    sort(vx.begin(), vx.end(), cmpx);
    sort(vy.begin(), vy.end(), cmpy);
    int sc = 0;
    for(int i = 1; i < n - 1; i++){
        // cout << "vx "<<vx[i][0]<< ' '<< vx[i][1]<< '-'<< vx[i - 1][0]<< ' '<< vx[i - 1][1]<< '-'<< vx[i + 1][0]<< ' '<< vx[i + 1][1]<< ' '<< vx[i][2]<< endl;
        // cout << "vy "<<vy[i][0]<< ' '<< vy[i][1]<< '-'<< vy[i - 1][0]<< ' '<< vy[i - 1][1]<< '-'<< vy[i + 1][0]<< ' '<< vy[i + 1][1]<< ' '<< vy[i][2]<< endl;

        if(vx[i][0] == vx[i + 1][0] && vx[i][0] == vx[i - 1][0] && vx[i][1] < vx[i + 1][1] && vx[i][1] > vx[i - 1][1]){
            vch[vx[i][2]]++;
        }
        if(vy[i][1] == vy[i + 1][1] && vy[i][1] == vy[i - 1][1] && vy[i][0] < vy[i + 1][0] && vy[i][0] > vy[i - 1][0]){
            vch[vy[i][2]]++;
        }
    }
    for(int i = 0; i < n; i++){
        // cout << i << ' ' <<vch[i] << endl;
        if(vch[i] == 2)
            sc++;
    }
    cout << sc;
    return 0;
}