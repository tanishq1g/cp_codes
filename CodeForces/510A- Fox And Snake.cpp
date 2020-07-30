#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    bool f1 = false, fm = true; 
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            for(int j = 0; j < m; j++){
                cout << "#";
            }   
        }
        else{
            if(f1){
                f1 = false;
                cout << "#";
            }
            else{
                f1 = true;
                cout << ".";
            }    
            for(int j = 1; j < m - 1 ; j++){
                cout << ".";
            }
            if(fm){
                fm = false;
                cout << "#";
            }
            else{
                fm = true;
                cout << ".";
            }    
        }
        cout << "\n";
    }
    return 0;
}