#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <bitset>
using namespace std;

// dynamic_programming
bool comp(vector<int> &a, vector<int> &b ){
    if(a[0] < b[0]){
        return true;
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,ma;
        cin >> n;
        vector<vector<int> > ve(n, vector<int> (2));
        for(int i = 0; i < n; i++){
            cin >> ve[i][0] >> ve[i][1];   
        }
        sort(ve.begin(), ve.end(), comp);
        vector<int> inc(n, 1);
        ma = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(ve[j][1] < ve[i][0]){
                    inc[i] = max(inc[i], inc[j] + 1);
                }
            }
            ma = max(ma, inc[i]);
        }
        cout << ma << endl;
    }
    return 0;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(ve.begin(), ve.end(), comp);
    vector<int> inc(n, 1);
    ma = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(ve[j][1] < ve[i][0]){
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
        ma = max(ma, inc[i]);
    }

}