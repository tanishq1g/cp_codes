#include <iostream>
#include <list>
using namespace std;

int main ()
{
  // constructors used in the same order as described above:
  list<int> first;                                // empty list of ints
  list<int> second (4,100);                       // four ints with value 100
  list<int> third (second.begin(),second.end());  // iterating through second
  list<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    cout << "The contents of fifth are: ";
    for (list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        cout << *it << ' ';

    cout << '\n';


// emplace front

    Inserts a new element at the beginning of the list, right before its current first element. This new element is constructed in place using args as the arguments for its construction.

    list< pair<int,char> > mylist;

    mylist.emplace_front(10,'a');
    mylist.emplace_front(20,'b');
    mylist.emplace_front(30,'c');

// push_front

    Inserts a new element at the beginning of the list, right before its current first element. The content of val is copied (or moved) to the inserted element.

    list<int> mylist (2,100);         // two ints with a value of 100
    mylist.push_front (200);
    mylist.push_front (300);

// pop back
    mylist.pop_back();

// back
    Returns a reference to the last element in the list container.
    list<int> mylist;

    mylist.push_back(10);
    int s = mylist.back(); will return 10;

// erase o(1)
    Removes from the list container either a single element (position) or a range of elements ([first,last)).
    list<int> mylist;
    list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);

                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^
  advance (it2,6);            // ^                 ^
  ++it1;                      //    ^              ^

  it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist.erase (it1,it2);     // 10 30 60 80 90
                              //        ^         

// remove all elements with the value O(n)
    int myints[]= {17,89,7,14};
    std::list<int> mylist (myints,myints+4);

    mylist.remove(89);
    Removes from the container all the elements that compare equal to val.
}

//cmp in pair
        vector<vector<int> > out(n, vector<int> (n, INT_MAX));

        int total = n * n, mdist, x, y, mix, miy;
        struct cmp{
            bool operator ()(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b){
                if(a.second < b.second)
                    return true;
                return false;
            }
        };
        set<pair<pair<int, int>, int>, cmp> lt;
