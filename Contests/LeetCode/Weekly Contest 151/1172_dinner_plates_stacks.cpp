#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

struct greaters{ 
  bool operator()(const long& a,const long& b) const{ 
    return a>b; 
  } 
}; 

class DinnerPlates {
    vector<stack<int>> vec;
    map<int, bool> lef;
    int sizev;
    int cap;
public:
    DinnerPlates(int capacity) {
        cap = capacity;
        sizev = 0;
    }
    
    void push(int val) {
        // cout<<"push "<<val<<'\n';
        if(sizev == 0){
            stack<int> st;
            st.push(val);
            vec.push_back(st);
            sizev++;
        }
        else{
            int i;
            if(lef.size() != 0){
                while(lef.begin()->first >= sizev)
                    lef.erase(lef.begin());
                vec[lef.begin()->first].push(val);
                if(vec[lef.begin()->first].size() == cap){
                    lef.erase(lef.begin());
                }
                return;
            }
            if(vec[sizev - 1].size() < cap){
                vec[sizev - 1].push(val);
                return;
            }
            stack<int> st;
            st.push(val);
            vec.push_back(st);
            sizev++;
        }
    }
    
    int pop() {
        if(sizev == 0)
            return -1;
        int x = vec[sizev - 1].top();
        // cout<<"pop "<<x<<'\n';
        vec[sizev - 1].pop();
        while(vec[sizev - 1].size() == 0){
            vec.pop_back();
            // cout<<"in\n";
            sizev--;
            // cout<<sizev<<'\n';
            if(sizev == 0)
                return x;
        }
        // cout<<"out\n";
        return x;
    }
    
    int popAtStack(int index) {
        if(index < sizev - 1){
            if(lef.find(index) == lef.end()){
                lef[index] = true;
            }
        }
        // cout<<"popatst "<<' '<<index<<'\n';
        if(index >= sizev)
            return -1;
        if(vec[index].size() == 0)
            return -1;
        int x = vec[index].top();
        // cout<<x<<'\n';
        vec[index].pop();
        if(index == sizev - 1){
            if(vec[index].size() == 0){
                vec.pop_back();
                sizev--;
            }
        }
        return x;
    }
};


