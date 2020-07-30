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


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */
void StackQueue :: push(int x)
 {
        // Your Code
        
        // Simple 
        s1.push(x);
        
 }
/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        // Your Code     
        
        // If S2 is empty tranfer all elements to S2 from S1 and pop out 1st element
        if(s2.empty()){
            if(s1.empty()){
                return -1;
            }
            else{
                while(!s1.empty()){
                    int ele=s1.top();
                    s1.pop();
                    s2.push(ele);
                }
                int ele=s2.top();
                s2.pop();
                return ele;
            }
        }
        // S2 is not empty so just pop out element from it
        else{
            int ele=s2.top();
            s2.pop();
            return ele;
        }
}
