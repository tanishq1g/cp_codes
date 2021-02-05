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

class Abc
{
public:
    int i;           //data variable
    void display()         //Member Function
    { 
        cout << "Inside Member Function\n";
    }
}; // Class ends here
class X
{
    public:
    static int i;
    X()
    {
        // construtor
        cout << i ;
    };
};
int X::i=1;

int main(){
    Abc obj;  // Creatig Abc class's object
    obj.display();  //Calling member function using class object
    long long int a = (((long long int)1)<<63);
    cout << a << '\n';
    X obj2;
    cout << obj2.i;   // prints value of i
    cout <<endl;
    int aa=10, b=0, c;
    // try block activates exception handling
    try 
    {
        if(b == 0)
        {
            // throw custom exception
            // throw "Division by zero not possible";
            c = aa/b;
        }
    }
    catch(char* ex) // catches exception
    {
        cout<<ex;
    }
    
    return 0;
}