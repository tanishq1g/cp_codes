#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    n++;m++;
    vector<vector<bool>> ve(n, vector<bool>(m, true));
    int x, y, x2, y2;
    cin >> x >> y;
    cout << x << ' ' << y << endl;
    ve[x][y] = false;
    int md;
    bool fill;
    for(int i = 1; i < k; i++){
        cin >> x >> y;
        if(ve[x][y]){
            cout << x << ' ' << y << endl;
            ve[x][y] = false;
        }else{
            md = max(n, m);
            fill = false;
            for(int d = 1; d <= md; d++){
                // cout << "  d "<<d<<'\n';
                for(int k, j = 1; j <= d && j < n; j++){

                    x2 = x - j;
                    // cout << "x2. " << x2 << endl;
                    if(x2 > 0){
                        k = d - j;
                        y2 = y - k;
                        // cout << "y2. " << y2 << endl;
                        if(y2 > 0){
                            if(ve[x2][y2]){
                                // cout <<"a "<< x2 << ' ' << y2 <<' ' << d <<'\n';
                                ve[x2][y2] = false;
                                cout << x2 << ' ' << y2 << endl;
                                fill = true;
                                break;
                            }
                        }
                        y2 = y + k;
                        // cout << "y2.. " << y2 << endl;
                        if(y2 < m){
                            if(ve[x2][y2]){
                                // cout <<"b "<< x2 << ' ' << y2 <<' ' << d <<'\n';
                                ve[x2][y2] = false;
                                cout << x2 << ' ' << y2 << endl;
                                fill = true;
                                break;
                            }
                        }
                    }

                    x2 = x;
                    // cout << "x2.. " << x2 << endl;
                    if(x2 < n){
                        k = d;
                        y2 = y - k;
                        // cout << "y2 " << y2 << endl;
                        if(y2 > 0){
                            if(ve[x2][y2]){
                                // cout <<"c "<< x2 << ' ' << y2 << ' ' << d <<'\n';
                                ve[x2][y2] = false;
                                cout << x2 << ' ' << y2 << endl;
                                fill = true;
                                break;
                            }
                        }
                        y2 = y + k;
                        // cout << "y2 " << y2 << endl;
                        if(y2 < m){
                            if(ve[x2][y2]){
                                // cout <<"d "<< x2 << ' ' << y2 << ' ' << d <<'\n';
                                ve[x2][y2] = false;    
                                cout << x2 << ' ' << y2 << endl;
                                fill = true;
                                break;
                            }
                        }
                    }

                    x2 = x + j;
                    // cout << "x2... " << x2 << endl;
                    if(x2 < n){
                        k = d - j;
                        y2 = y - k;
                        // cout << "y2 " << y2 << endl;
                        if(y2 > 0){
                            if(ve[x2][y2]){
                                // cout <<"c "<< x2 << ' ' << y2 << ' ' << d <<'\n';
                                ve[x2][y2] = false;
                                cout << x2 << ' ' << y2 << endl;
                                fill = true;
                                break;
                            }
                        }
                        y2 = y + k;
                        // cout << "y2 " << y2 << endl;
                        if(y2 < m){
                            if(ve[x2][y2]){
                                // cout <<"d "<< x2 << ' ' << y2 << ' ' << d <<'\n';
                                ve[x2][y2] = false;
                                cout << x2 << ' ' << y2 << endl;
                                fill = true;
                                break;
                            }
                        }
                    }

                }
                if(fill)
                    break;
            }
        }
    }
    return 0;
}