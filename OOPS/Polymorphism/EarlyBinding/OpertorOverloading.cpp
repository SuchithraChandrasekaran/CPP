/* Operator overloading is a compile-time polymorphism/Early Binding
 
C++ has the ability to provide the operators with a special meaning for a data type, 
this ability is known as operator overloading. 
For example, we can overload an operator ‘+’ in a class like String 
so that we can concatenate two strings by just using +
*/

#include <iostream>
#include <cstring>  // For strcat
using namespace std;

class MyString 
{
public:
    char str[100];

    MyString(const char* s)
    { 
        str[0] = '\0';  // Initialize empty string
        strcat(str, s);  // Directly copy input
    }

    MyString operator+(MyString obj) 
    {  
        return MyString(strcat(str, obj.str));  // Directly return concatenated string
    }
};

int main() 
{
    MyString s1("Hello "), s2("World!");
    MyString s3 = s1 + s2;
    cout << s3.str << endl;  // Output: Hello World!
    return 0;
}
