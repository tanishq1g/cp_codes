#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(
        a + b + c, max(
            a + b * c, max(
                (a + b) * c, max(
                    a * b + c, max(
                        a * (b + c), a * b * c
                    )
                )
            )
        )
    );
    return 0;
}