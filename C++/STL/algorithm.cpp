#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    min(x,y)
    // x and y can only be integers and not overloaded functions
    max(x,y)
    sort(first_iterator, last_iterator) //To sort the given vector.
    reverse(first_iterator, last_iterator) //To reverse a vector.
    *max_element (first_iterator, last_iterator)// To find the maximum element of a vector.
    *min_element (first_iterator, last_iterator)// To find the minimum element of a vector.
    accumulate(first_iterator, last_iterator, initial value of sum)// Does the summation of vector elements

// Initializing vector with array values
    int arr[] = {10, 20, 5, 23 ,42 , 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);

    cout << "Vector is: ";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";

// Sorting the Vector in Ascending order
    sort(vect.begin(), vect.end());

// Sorting the Vector in descending order
    sort(vect.begin(), vect.end(), greater<int>());
    
    bool cmp(vector<int> v1, vector<int> v2){
        return v1[0] < v2[0];
    }
    vector<vector<int>> v(n, vector<int> (2, 0));
    sort(v.begin(), v.end(), cmp);

    
// Reversing the Vector
    reverse(vect.begin(), vect.end());

    cout << "\nVector after reversing is: ";
    for (int i=0; i<6; i++)
        cout << vect[i] << " ";

    cout << "\nMaximum element of vector is: ";
    cout << *max_element(vect.begin(), vect.end());

    cout << "\nMinimum element of vector is: ";
    cout << *min_element(vect.begin(), vect.end());

    // Starting the summation from 0
    cout << "\nThe summation of vector elements is: ";
    cout << accumulate(vect.begin(), vect.end(), 0);



	result = pow(base, exponent);

    double x = 10.25, result;
	result = sqrt(x)

// sorting strings
    sort(str.begin(), sort.end());

//sorting based on comparator
static bool comparator( vector<int>& a, vector<int>& b )
    {
        return a[0] < b[0];
    }
    vector<vector<int>>& intervals
    //Sort the inetrvals first based on the start of interval
        sort( intervals.begin(), intervals.end(), comparator );

// find
Returns an iterator to the first element in the range [first,last) that compares equal to val. If no such element is found, the function returns last.
    // using find with vector and iterator:
    vector<int> myvector { 10, 20, 30, 40 };
    vector<int>::iterator it;

    it = find (myvector.begin(), myvector.end(), 30);
    if (it != myvector.end())
        cout << "Element found in myvector: " << *it << '\n';
    else
        cout << "Element not found in myvector\n";

        return 0;
    }

//binary search
    // Parameters
    // first, last
    Forward iterators to the initial and final positions of a sorted (or properly partitioned) sequence. The range used is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.
    // val
    Value to search for in the range.
    For (1), T shall be a type supporting being compared with elements of the range [first,last) as either operand of operator<.
    // comp
    Binary function that accepts two arguments of the type pointed by ForwardIterator (and of type T), and returns a value convertible to bool. The value returned indicates whether the first argument is considered to go before the second.
    The function shall not modify any of its arguments.
    This can either be a function pointer or a function object.

    // Return value
    true if an element equivalent to val is found, and false otherwise.

    // Complexity
    On average, logarithmic in the distance between first and last: Performs approximately log2(N)+2 element comparisons (where N is this distance).

    binary_search (v.begin(), v.end(), 3)

// upper bound , lower bound - works on sorted arrays
    parameters same as above
    // Return value for upper_bound
    An iterator to the upper bound position for val in the range.
    If no element in the range compares greater than val, the function returns last.
    // Return value for lower_bound
    An iterator to the lower bound of val in the range.
    If all the element in the range compare less than val, the function returns last.

    // 10 10 10 20 20 20 30 30

    std::vector<int>::iterator low,up;
    low=std::lower_bound (v.begin(), v.end(), 20); // 3
    up= std::upper_bound (v.begin(), v.end(), 20); // 6

    Performs approximately log2(N)+1 element comparisons (where N is this distance).