#include <algorithm>
using namespace std;

int main() {
// Maps are a part of the C++ STL.Maps are associative containers that store elements formed by a
// combination of a key value and a mapped value, following a specific order.The mainly used member
// functions of maps are:

// Map Template:
	std::map <key_type, data_type>;

	// Declaration:
	map<string, int>m; //Creates a map m where key_type is of type string and data_type is of type int.

	// Size:
	int length = m.size(); //Gives the size of the map.

    // find
    map.find(key);
    // will return iterator to record if found, if not will return map.end()
    map <int, int>::iterator it;
    it = map.find(key);
    it->first //prints the key
    it->second // prints the value

	// Insert:
	m.insert(make_pair("hello", 9)); //Here the pair is inserted into the map where the key is "hello" and the value associated with it is 9.
    m["hello"] = 9;
    m["hello"] += 9;  // therefore simple m[name] creates an entry 

	// Erasing an element:
	m.erase(val); //Erases the pair from the map where the key_type is val.

	// Finding an element:
	map<string, int>::iterator itr = m.find(val); //Gives the iterator to the element val if it is found otherwise returns m.end() .
Ex: map<string, int>::iterator itr = m.find("Maps"); //If Maps is not present as the key value then itr==m.end().

// Accessing the value stored in the key:
	To get the value stored of the key "MAPS" we can do m["MAPS"] or we can get the iterator using the find function and then by itr->second we can access the value

		Insertion : O(1) expected, O(n) worst case
		Lookup: O(1) expected, O(n) worst case
		Deletion: O(1) expected, O(n) worst case

    Some basic functions associated with Map:
begin() – Returns an iterator to the first element in the map
end() – Returns an iterator to the theoretical element that follows last element in the map
size() – Returns the number of elements in the map
max_size() – Returns the maximum number of elements that the map can hold
empty() – Returns whether the map is empty
pair insert(keyvalue, mapvalue) – Adds a new element to the map
erase(iterator position) – Removes the element at the position pointed by the iterator
erase(const g)– Removes the key value ‘g’ from the map
clear() – Removes all the elements from the map

      iterator lower_bound (const key_type& k);
const_iterator lower_bound (const key_type& k) const;
Return iterator to lower bound
Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).

    map upper_bound() function in C++ STL
The map::upper_bound() is a built-in function in C++ STL which returns an iterator pointing to the immediate next element just greater than k. If the key passed in the parameter exceeds the maximum key in the container, then the iterator returned points to the number of elements in the map container as key and element=0.

    // empty map container 
    map<int, int> gquiz1; 
  
    // insert elements in random order 
    gquiz1.insert(pair<int, int>(1, 40)); 
    gquiz1.insert(pair<int, int>(2, 30)); 
    gquiz1.insert(pair<int, int>(3, 60)); 
    gquiz1.insert(pair<int, int>(4, 20)); 
    gquiz1.insert(pair<int, int>(5, 50)); 
    gquiz1.insert(pair<int, int>(6, 50)); 
    gquiz1.insert(pair<int, int>(7, 10)); 
  
    // printing map gquiz1 
    map<int, int>::iterator itr; 
    cout << "\nThe map gquiz1 is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    cout << endl; 
  
    // assigning the elements from gquiz1 to gquiz2 
    map<int, int> gquiz2(gquiz1.begin(), gquiz1.end()); 
  
    // print all elements of the map gquiz2 
    cout << "\nThe map gquiz2 after"
         << " assign from gquiz1 is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    cout << endl; 
  
    // remove all elements up to 
    // element with key=3 in gquiz2 
    cout << "\ngquiz2 after removal of"
            " elements less than key=3 : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3)); 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
  
    // remove all elements with key = 4 
    int num; 
    num = gquiz2.erase(4); 
    cout << "\ngquiz2.erase(4) : "; 
    cout << num << " removed \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
  
    cout << endl; 
  
    // lower bound and upper bound for map gquiz1 key = 5 
    cout << "gquiz1.lower_bound(5) : "
         << "\tKEY = "; 
    cout << gquiz1.lower_bound(5)->first << '\t'; 
    cout << "\tELEMENT = "
         << gquiz1.lower_bound(5)->second << endl; 
    cout << "gquiz1.upper_bound(5) : "
         << "\tKEY = "; 
    cout << gquiz1.upper_bound(5)->first << '\t'; 
    cout << "\tELEMENT = "
         << gquiz1.upper_bound(5)->second << endl; 
  
	return 0;
}



C++ Standard Template Library provides maps and sets which are implemented > internally using balanced red black trees. We explore maps here for now, although set is very much similar. 
Map declaration :

    map<int, int> A; // O(1) declaration which declares an empty tree map.
Insert a new key, value pair K, V:

    A[K] = V; // O(log n). Note that we expect key K to be unique here. If you have keys that will repeat, take a look at multimaps. 
Delete a key K:

    A.erase(K); // O(log n)
Search if a key K exists in map:

    A.find(K) != A.end()  // O(log n)
Search for the value with key K:

     A[K]     // O(log n)
Find minimum key K in the map ( if the map is not empty ) :

    (A.begin())->first     // O(1)
Find maximum key K in the map ( if map is not empty ) :

    (A.rbegin())->first     // O(1)
Iterate over keys in sorted order :

    for (map<int,int>::iterator it = A.begin(); it != A.end(); ++it) {
        // it->first has the key, it->second has the value. 
    }
Find closest key K > x :

    (A.upper_bound(x))->first     // O(log n). Do need to handle the case when x is more than or equal to the max key in the map. 
Find closest key K >= x :

    (A.lower_bound(x))->first     // O(log n). Do need to handle the case when x is more than the max key in the map.
Size ( number of entries in the map ) :

    A.size()