#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
using namespace std;

bool islucky(int x){
    int r;
    do{
        r = x % 10;
        if(r != 4 && r != 7)
            return false;
        x = x / 10;
    }while(x != 0);
    return true;
}

int main(){
    int n;
    cin  >> n;
    for(int i = 1; i <= n; i++){
        // cout<<i<<'\n';
        if(n % i == 0 && islucky(i)){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}


int main() {
    int n;
    cin>>n;
    bool flag=0;
    int arr[12]={4,7,47,74,44,444,447,474,477,777,774,744};
    for(int i=0;i<12;i++){
        if(n%arr[i]==0){
            flag=true;
        }
    }
    if(flag)
    cout<<"YES";
    else
        cout<<"NO";
    return 0;
}