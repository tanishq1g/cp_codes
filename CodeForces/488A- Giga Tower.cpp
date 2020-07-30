#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

bool ch8(long long int x){
    while(x != 0){
        // cout << "  "<<x<<' '<<x % 10<<' '<<x/10<<endl;
        if(abs(x % 10) == 8){
            return true;
        }
        x = x / 10;
    }
    return false;
}
int main(){
    long long int a;
    cin >> a;
    // vector<int> ve{8, 18, 28, 38, 48, 58, 68, 78, 80, 88, 98};
    long long int c = 0;
    do{
        a++;
        c++;
        // cout << a << ' '<<c <<endl;
    }while(!ch8(a));
    cout<<c;
    return 0;
}

int main()
{
    int n, c(0);
    cin >> n;

    while (true)
    {
        n++, c++;
        stringstream ss;
        string s;
        ss << n;
        ss >> s;
        if (s.find('8') != -1)
        {
            cout << c << endl;
            return 0;
        }
    }
}