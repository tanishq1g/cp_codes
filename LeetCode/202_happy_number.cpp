#include <unordered_map>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int temp = 0, rem, div;
        unordered_map<int,bool> m;
        while(n!=1){
            // cout<<n<<'\n';
            if(m.find(n) != m.end()){
                return false;
            }
            m[n] = true;
            temp = 0;
            if(n<10){
                n= n*n;
                continue;
            }
            while(n>0){
                rem = n%10;
                temp += rem*rem;
                n = n/10;
            }
            n = temp;
        }
        return true;
    }
};
int main(){
    Solution sol;
    cout<<sol.isHappy(19);
    return 0;
}