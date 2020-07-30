#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> ve(n);
    string ch;
    int count = 0;
    for(int i = 0; i < n; i++){
        cin >> ch;
        ve[i] = ch;
        for(int j = 0; j < n; j++){
            if(ve[i][j] != 'o')
                continue;
            if(i - 1 >= 0){
                // if(ve[i - 1][j] == 'o')
                //     count++;
                if(j - 1 >= 0){
                    if(ve[i - 1][j - 1] == 'o')
                        count++;
                }
                if(j + 1 < n)
                    if(ve[i - 1][j + 1] == 'o')
                        count++;
            }
            // if(j - 1 >= 0){
            //     if(ve[i][j - 1] == 'o')
            //         count++;
            // }
        }
        // cout << ve[i] << ' '<<count<<endl;
    }
    // cout<<count<<endl;
    if(count % 2)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}