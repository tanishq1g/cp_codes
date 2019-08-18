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

list< std::pair<int,char> > mylist;

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


  return 0;
}