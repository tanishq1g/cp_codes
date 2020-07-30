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
#include <stack>
#include <utility>
using namespace std;
#define INF 1e7

// STACK AND HEAPS



/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin(){
    if(s.empty())
        return -1;
    return minEle;
}

/*returns poped element from stack*/
int _stack ::pop(){
    if(s.empty())
        return -1;
    int x = s.top();
    s.pop();
    if(minEle > x){
        int ret = minEle;
        minEle = 2 * minEle - x;
        return ret;
    }
    return x;
}

/*push element x into the stack*/
void _stack::push(int x){
    if(s.empty()){
        s.push(x);
        minEle = x;
        return;
    }
    if(minEle < x){
        s.push(x);
    }
    else{
        s.push(2*x - minEle);
        minEle = x;

    }
}
