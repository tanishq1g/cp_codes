#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, x, y;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v[i][0] = x; 
        v[i][1] = y;
    }
    int c = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) 
                continue;
            if(v[i][0] == v[j][1])
                c++;
        }
    }
    cout<<c;
    return 0;
}


int main()
{
    int n;
    cin >> n;

    int number(0);
    vector<int> h(n), a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i] >> a[i];
        for (int j = 0; j < i; ++j)
        {
            if (h[i] == a[j])
            {
                number += 1;
            }
            if (a[i] == h[j])
            {
                number += 1;
            }
        }
    }
    cout << number << endl;
    return 0;
}
