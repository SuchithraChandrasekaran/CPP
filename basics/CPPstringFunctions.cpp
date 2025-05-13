#include <iostream>
#include <string>
#include <algorithm> // for transform

using namespace std;

int main() 
{
    string str1 = "HelloWorld";
    string str2 = "World";
    string str3;

    // Length
    cout << "Length of str1: " << str1.length() << endl;

    // Copy
    str3 = str1;
    cout << "Copied str1 to str3: " << str3 << endl;

    // Concatenate
    string combined = str1 + str2;
    cout << "Concatenated str1 + str2: " << combined << endl;

    // Compare
    if (str1 == str2)
        cout << "str1 and str2 are equal" << endl;
    else
        cout << "str1 and str2 are not equal" << endl;

    // Substring (first 5 chars)
    string substr = str1.substr(0, 5);
    cout << "Substring (first 5 characters): " << substr << endl;

    // Convert to uppercase
    string upperStr = str1;
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    cout << "Uppercase str1: " << upperStr << endl;

    // Convert to lowercase
    string lowerStr = str1;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    cout << "Lowercase str1: " << lowerStr << endl;

    // Find character
    size_t pos = str1.find('o');
    if (pos != string::npos)
        cout << "First occurrence of 'o' in str1: " << pos << endl;
    else
        cout << "'o' not found in str1" << endl;

    // Find substring
    if (str1.find("World") != string::npos)
        cout << "Substring 'World' found in str1" << endl;
    else
        cout << "Substring 'World' not found in str1" << endl;

    return 0;
}
/* Expected Output:
Length of str1: 10
Copied str1 to str3: HelloWorld
Concatenated str1 + str2: HelloWorldWorld
str1 and str2 are not equal
Substring (first 5 characters): Hello
Uppercase str1: HELLOWORLD
Lowercase str1: helloworld
First occurrence of 'o' in str1: 4
Substring 'World' found in str1
*/


