#include <string>
#include <algorithm>
using namespace std;

int main() {
    C++ provides a nice alternative data type to manipulate strings, and the data type is conveniently called string. Some of its widely used features are the following:

    Declaration:

    string a = "abc";
    Size:

    int len = a.size();
    Concatenate two strings:

    string a = "abc";
    string b = "def";
    string c = a + b; // c = "abcdef".
    Accessing  element:

    string s = "abc";
    char   c0 = s[0];   // c0 = 'a'
    char   c1 = s[1];   // c1 = 'b'
    char   c2 = s[2];   // c2 = 'c'

    string substr (size_t pos = 0, size_t len = npos) const;
    pos
Position of the first character to be copied as a substring
    len
Number of characters to include in the substring (if the string is shorter, as many characters as possible are used).

    s[0] = 'z';         // s = "zbc"
    P.S.: We will use cin/cout to read/write a string.

}