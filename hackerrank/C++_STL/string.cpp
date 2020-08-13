#include <string>
#include <algorithm>
using namespace std;

0 - 48 ; 9 - 57
A - 65 ; Z - 90
a - 97 ; z - 122
a - A = 32

int main() {
    // C++ provides a nice alternative data type to manipulate strings, and the data type is conveniently called string. Some of its widely used features are the following:

// Declaration:

    string a = "abc";

// Size:

    int len = a.size();

// Concatenate two strings:

    string a = "abc";
    string b = "def";
    string c = a + b; // c = "abcdef".

// add char to string

    string a += 'c';

    // Accessing  element:

    string s = "abc";
    char   c0 = s[0];   // c0 = 'a'
    char   c1 = s[1];   // c1 = 'b'
    char   c2 = s[2];   // c2 = 'c'

// substr

    string substr (size_t pos = 0, size_t len = npos) const;
    pos
Position of the first character to be copied as a substring
    len
Number of characters to include in the substring (if the string is shorter, as many characters as possible are used).

// find

    size_t find (const string& str, size_t pos = 0) const;
    string str ("There are two needles in this haystack with needles.");
    string str2 ("needle");
    // different member versions of find in the same order as above:
    size_t found = str.find(str2);
    Searches the string for the first occurrence of the sequence specified by its arguments.
    When pos is specified, the search only includes characters at or after position pos, ignoring any possible occurrences that include characters before pos.
    if no match returns -1
        s[0] = 'z';         // s = "zbc"
        P.S.: We will use cin/cout to read/write a string.


    for ( string::iterator it=str.begin(); it!=str.end(); ++it)
        cout << *it;
    cout << '\n';

// lower upper case
    string s = "Aa";
    tolower(s)
    toupper(s)

// convert to string
    to_string(12); --will convert 12 to str

    }

// string to int 
int stoi (const string&  str, size_t* idx = 0, int base = 10)
str
    String object with the representation of an integral number.
idx
    Pointer to an object of type size_t, whose value is set by the function to position of the next character in str after the numerical value.
    This parameter can also be a null pointer, in which case it is not used.
base
    Numerical base (radix) that determines the valid characters and their interpretation.
    If this is 0, the base used is determined by the format in the sequence (see strtol for details). Notice that by default this argument is 10, not 0.

    stoi("123") - 123
    stoi("2001, A Space Odyssey") - 2001
    stoi("40c3", nullptr, 16) - 16579
    stoi("-10010110001", nullptr, 2) - -1201
    stoi("0x75", nullptr, 0) - 127 (auto)


// COMPARE

string str1 ("green apple");
  string str2 ("red apple");

  if (str1.compare(str2) != 0)
    cout << str1 << " is not " << str2 << '\n';

  if (str1.compare(6,5,"apple") == 0) //IF 5 is greater than the string length, it throws out_of_range.
    cout << "still, " << str1 << " is an apple\n";

  if (str2.compare(str2.size()-5,5,"apple") == 0)
    cout << "and " << str2 << " is also an apple\n";

  if (str1.compare(6,5,str2,4,5) == 0)
    cout << "therefore, both are apples\n";


// input strings
    without spaces -- cin >> s;
    with spaces -- getline(cin, s)
            int t;
            cin >> t;
            cin.ignore();
            while(t--){
                string s;
                getline(cin, s);
                
// front, back of string - returns char
    str.front()
    str.back()

// string insert

    string str="to be question";
    string str2="the ";
    string str3="or not to be";
    string::iterator it;

    // used in the same order as described above:
    str.insert(6,str2);                 // to be (the )question
    str.insert(6,str3,3,4);             // to be (not )the question
    str.insert(10,"that is cool",8);    // to be not (that is )the question
    str.insert(10,"to be ");            // to be not (to be )that is the question
    str.insert(15,1,':');               // to be not to be(:) that is the question
    it = str.insert(str.begin()+5,','); // to be(,) not to be: that is the question
    str.insert (str.end(),3,'.');       // to be, not to be: that is the question(...)
    str.insert (it+2,str3.begin(),str3.begin()+3); // (or )
   
    string (1)	
    string& insert (size_t pos, const string& str);
    substring (2)	
    string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);
    c-string (3)	
    string& insert (size_t pos, const char* s);
    buffer (4)	
    string& insert (size_t pos, const char* s, size_t n);
    fill (5)	
    string& insert (size_t pos, size_t n, char c);
        void insert (iterator p, size_t n, char c);
    single character (6)	
    iterator insert (iterator p, char c);
    range (7)	
    template <class InputIterator>
    void insert (iterator p, InputIterator first, InputIterator last);

// string erase
    string& erase (size_t pos = 0, size_t len = npos);
    
    string str ("This is an example sentence.");
    cout << str << '\n';
                                            // "This is an example sentence."
    str.erase (10,8);                        //            ^^^^^^^^
    cout << str << '\n';
                                            // "This is an sentence."
    str.erase (str.begin()+9);               //           ^
    cout << str << '\n';
                                            // "This is a sentence."
    str.erase (str.begin()+5, str.end()-9);  //       ^^^^^
    cout << str << '\n';
                                            // "This sentence."