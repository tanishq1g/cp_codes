#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class MinStack {
private:
    class Data {
    public:
        Data(int v, int m) : val(v), min(m) {}
        int val;
        int min;
    };
    stack<Data> s;
public:
    void push(int x) { s.push(Data(x, s.empty() ? x : min(x, s.top().min))); }
    void pop() { s.pop(); }
    int top() { return s.top().val; }
    int getMin() { return s.top().min; }
};

class MinStack {
public:
    stack<long long int> s;
    long long int minele;
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(long long int x) {
        if(s.empty()){
            s.push(x);
            minele = x;
        }
        else{
            if(x < minele){
                long long int l = 2*x - minele;
                s.push(l);
                minele = x;
            }
            else
                s.push(x);
        }
    }

    void pop() {
        long long int p = s.top();
        if(p < minele){
            minele = 2*minele - p;
        }
        s.pop();
    }

    long long int top() {
        long long int p = s.top();
        if(p < minele){
            return 2*minele - p;
        }
        return p;
    }

    long long int getMin() {
        return minele;
    }
};

int main(){
    MinStack sol;

    sol.push(-2);
    sol.push(0);
    sol.push(-3);
    cout<<sol.getMin()<<'\n';
    sol.pop();
    cout<<sol.top()<<'\n';
    cout<<sol.getMin()<<'\n';

    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */