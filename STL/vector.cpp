#include <algorithm>
using namespace std;

int main() {
//You are given  integers.Sort the  integersand print the sorted order.
//Store the  integers in a vector.Vectors are sequence containers representing arrays that can change in size.

//Declaration:
	vector<int>v; (creates an empty vector of integers);
		
//Size :

		int size = v.size();
	
//Pushing an integer into a vector :

	v.push_back(x); (where x is an integer.The size increases by 1 after this.);
		
//Popping the last element from the vector :

	v.pop_back(); (After this the size decreases by 1);
		
// Sorting a vector :

	sort(v.begin(), v.end()); (Will sort all the elements in the vector);
	return 0;
}