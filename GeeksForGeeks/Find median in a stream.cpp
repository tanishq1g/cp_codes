#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <climits>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// HEAPS

int main(){
    int n, x, med;
    cin >> n;
    priority_queue<int> ma; //lowerhealf
    priority_queue<int, vector<int>, greater<int> > mi; //upperhalf
    cin >> x;
    med = x;
    cout << med << '\n';
    ma.push(x);
    int su, sl;
    for(int i = 1; i < n; i++){
        cin >> x;
        if(x > med){
            mi.push(x);
        }
        else{
            ma.push(x);
        }
        su = mi.size();
        sl = ma.size();
        if(su > sl + 1){
            ma.push(mi.top());
            mi.pop();
            med = (mi.top() + ma.top()) / 2;
        }
        else if(sl > su + 1){
            mi.push(ma.top());
            ma.pop();
            med = (mi.top() + ma.top()) / 2;
        }
        else if(su == sl){
            med = (mi.top() + ma.top()) / 2;
        }
        else{
            med = (su > sl) ? mi.top() : ma.top();
        }
        cout << med << '\n';
    }
    return 0;
}