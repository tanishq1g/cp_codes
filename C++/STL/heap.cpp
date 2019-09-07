// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  std::make_heap (v.begin(),v.end());
  std::cout << "initial max heap   : " << v.front() << '\n';

  std::pop_heap (v.begin(),v.end()); v.pop_back();
  std::cout << "max heap after pop : " << v.front() << '\n';

  v.push_back(99); std::push_heap (v.begin(),v.end());
  std::cout << "max heap after push: " << v.front() << '\n';

  std::sort_heap (v.begin(),v.end());

  std::cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    std::cout << ' ' << v[i];

  std::cout << '\n';


struct greaters{ 
  bool operator()(const long& a,const long& b) const{ 
    return a>b; 
  } 
}; 
  
int main() 
{ 
    // initializing vector; 
    vector<int> vi = { 15, 6, 7, 9, 11, 45 }; 
      
    // using make_heap() to transform vector into 
    // a min heap 
    make_heap(vi.begin(),vi.end(), greaters()); 
      
    // checking if heap using  
    // front() function 
    cout << "The minimum element of heap is : "; 
    cout << vi.front() << endl; 
      
} 


  return 0;
}