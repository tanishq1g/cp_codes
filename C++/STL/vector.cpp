#include <algorithm>
using namespace std;

int main() {
//You are given  integers.Sort the  integersand print the sorted order.
//Store the  integers in a vector.Vectors are sequence containers representing arrays that can change in size.

//Declaration:
	vector<int>v; (creates an empty vector of integers);

	vector<int> v(2, 100);   // =>  [100,100];

        // constructors used in the same order as described above:
    vector<int> first;                                // empty vector of ints
    vector<int> second (4,100);                       // four ints with value 100
    vector<int> third (second.begin(),second.end());  // iterating through second
    vector<int> fourth (third);                       // a copy of third

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    std::cout << "The contents of fifth are:";
    for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

//Size :

		int size = v.size();

//Pushing an integer into a vector :

	v.push_back(x); (where x is an integer.The size increases by 1 after this.);

//Popping the last element from the vector :

	v.pop_back(); (After this the size decreases by 1);

// Sorting a vector :

	sort(v.begin(), v.end()); (Will sort all the elements in the vector);

// Iterators:

v.begin() //: Return iterator to beginning (public member function )
v.end() //: Return iterator to end (public member function )
v.rbegin() //: Return reverse iterator to reverse beginning (public member function )
v.rend() //: Return reverse iterator to reverse end (public member function )


// single element (1)
	iterator insert (const_iterator position, const value_type& val);
// fill (2)
	iterator insert (const_iterator position, size_type n, const value_type& val);
// range (3)
	template <class InputIterator>
	iterator insert (const_iterator position, InputIterator first, InputIterator last);
// move (4)
	iterator insert (const_iterator position, value_type&& val);
// initializer list (5)
	iterator insert (const_iterator position, initializer_list<value_type> il);

			std::vector<int> myvector (3,100);
			std::vector<int>::iterator it;

			it = myvector.begin();
			it = myvector.insert ( it , 200 );

			myvector.insert (it,2,300);

			// "it" no longer valid, get a new one:
			it = myvector.begin();

			std::vector<int> anothervector (2,400);
			myvector.insert (it+2,anothervector.begin(),anothervector.end());

			int myarray [] = { 501,502,503 };
			myvector.insert (myvector.begin(), myarray, myarray+3);

			std::cout << "myvector contains:";
			for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
			std::cout << '\n';

// concatenating two vectors
vector1.insert( vector1.end(), vector2.begin(), vector2.end() );

// 2D VECTORS

    vector<vector<int> > vect{ { 1, 2, 3 },
                               { 4, 5, 6 },
                               { 7, 8, 9 } };

    // Displaying the 2D vector
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++)
            cout << vect[i][j] << " ";
        cout << endl;
    }

    // will intialize a 2d vector if size 4,5 with defult value 1 : fill constructor
    vector<vector<int>> vect(4, vector<int>(5, 1));

	return 0;
}