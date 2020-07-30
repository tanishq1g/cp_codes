#include <algorithm>
#include <unordered_map>
using namespace std;
Insertion : O(1) expected, O(n) worst case
Lookup: O(1) expected, O(n) worst case
int main() {
// unordered_map is an associated container that stores elements formed by combination of key value and a mapped value. The key value is used to uniquely identify the element and mapped value is the content associated with the key. Both key and value can be of any type predefined or user-defined.
// Internally unordered_map is implemented using Hash Table, the key provided to map are hashed into indices of hash table that is why performance of data structure depends on hash function a lot but on an average the cost of search, insert and delete from hash table is O(1).
    // Declaring umap to be of <string, int> type
    // key will be of string type and mapped value will
    // be of double type
    unordered_map<string, int> umap;

// inserting values by using [] operator
    umap["GeeksforGeeks"] = 10;
    umap["Practice"] = 20;
    umap["Contribute"] = 30;

// Traversing an unordered map
    for (auto x : umap)
      cout << x.first << " " << x.second << endl;

// find
    // Searches the container for an element with k as key and returns an iterator to it if found, otherwise it returns an iterator to unordered_map::end (the element past the end of the container).
    umap.find(23)

// number of elements
    umap.size()
// erase

    by position (1)
    iterator erase ( const_iterator position );
    by key (2)
    size_type erase ( const key_type& k );
    range (3)
    iterator erase ( const_iterator first, const_iterator last );

    // erase examples:
    mymap.erase ( mymap.begin() );      // erasing by iterator
    mymap.erase ("France");             // erasing by key
    mymap.erase ( mymap.find("China"), mymap.end() ); // erasing by range

unordered_map<string,string> mymap;
  mymap = {{"Australia","Canberra"},{"U.S.","Washington"},{"France","Paris"}};

  cout << "mymap contains:";
  for ( auto it = mymap.begin(); it != mymap.end(); ++it )
    cout << " " << it->first << ":" << it->second;
  cout << endl;

  cout << "mymap's buckets contain:\n";
  for ( unsigned i = 0; i < mymap.bucket_count(); ++i) {
    cout << "bucket #" << i << " contains:";
    for ( auto local_it = mymap.begin(i); local_it!= mymap.end(i); ++local_it )
      cout << " " << local_it->first << ":" << local_it->second;
    cout << endl;
  }

}