#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    min(x,y)
    // x and y can only be integers and not overloaded functions

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

    cout << "\nVector after sorting is: ";
    for (int i=0; i<n; i++)
       cout << vect[i] << " ";

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
// using std::find with vector and iterator:
  std::vector<int> myvector { 10, 20, 30, 40 };
  std::vector<int>::iterator it;

  it = find (myvector.begin(), myvector.end(), 30);
  if (it != myvector.end())
    std::cout << "Element found in myvector: " << *it << '\n';
  else
    std::cout << "Element not found in myvector\n";

    return 0;
}