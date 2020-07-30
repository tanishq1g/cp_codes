#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    long long int n, k;
    cin >> n >> k;
    // cout<<n<<k;
    if(n % 2 == 0){
        if(k <= n / 2){
            cout << 2 * k - 1;
        }
        else{
            cout << 2 * (k - n / 2);
        }
    }
    else{
        if(k <= (n / 2) + 1){
            cout << 2 * k - 1;
        }
        else{
            cout << 2 * (k - (n / 2) - 1);
        }
    }
    return 0;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    if (k <= (n + 1) / 2)
    {
        cout << k * 2 - 1 << endl;
    }
    else
    {
        cout << (k - (n + 1) / 2) * 2 << endl;
    }
    return 0;
}