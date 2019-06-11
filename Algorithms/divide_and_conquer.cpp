#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

int func(vector<int> arr, int l, int r){
    if(l == r){
        // breakcondition
    }
    int m = (l + r) / 2;
    int left = func(arr, l, m);
    int right = func(arr, m + 1, r);

    // merge operation

    return val

}

int base(vector<int> arr){
    return func(arr, 0, arr.size());
}