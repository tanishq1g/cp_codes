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
    int t;
    cin >> t;
    while(t--){
        int k, n, x;
        cin >> k >> n;
        priority_queue<int, vector<int>, greater<int> > mh;
        int i = 0;
        for( ; i < k - 1; i++){
            cin >> x;
            mh.push(x);
            cout << -1 << ' ';
        }        
        cin >> x;
        mh.push(x);
        cout << mh.top() << ' ';
        i++;
        for( ; i < n; i++){
            cin >> x;
            if(x >= mh.top()){
                mh.push(x);
                mh.pop();
            }
            cout << mh.top() << ' ';
        }
        cout << '\n';
    }
    return 0;
}