#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip> 
using namespace std;

// dynamic programming

int main()
{
    int n, l(1), ml(1);
    cin >> n;
    int profits[n];

    for (int i = 0; i < n; i++)
    {
        cin >> profits[i];
        if (i > 0)
            if (profits[i] >= profits[i - 1])
            {
                l++;
                ml = max(ml, l);
            }
            else
                l = 1;
    }

    cout << ml << endl;
    return 0;
}