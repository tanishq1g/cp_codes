#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec;
    int num;
    while(n--){
        cin >> num;
        vec.push_back(num);
    }
    int s = vec.size();
    sort(vec.begin(), vec.end());
    int sum = 0;
    for(int i = 0; i < s; i++){
        sum += vec[i];
    }
    int ch = 0;
    for(int i = s - 1; i >= 0; i--){
        ch += vec[i];
        sum -= vec[i];
        if(ch > sum){
            cout << s - i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}