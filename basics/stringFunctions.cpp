#include <iostream>
#include <cstring>
#include <cctype> // For toupper, tolower

using namespace std;

int main() 
{
    char str1[100] = "HelloWorld";
    char str2[100] = "World";
    char str3[100];

    // Length
    cout << "Length of str1: " << strlen(str1) << endl;

    // Copy
    strcpy(str3, str1);
    cout << "Copied str1 to str3: " << str3 << endl;

    // Concatenate
    strcat(str1, str2);
    cout << "Concatenated str1 + str2: " << str1 << endl;

    // Compare
    if (strcmp(str1, str2) == 0)
        cout << "str1 and str2 are equal" << endl;
    else
        cout << "str1 and str2 are not equal" << endl;

    // Substring (first 5 chars of str1)
    char substr[10];
    strncpy(substr, str1, 5);
    substr[5] = '\0'; // Null-terminate
    cout << "Substring (first 5 characters): " << substr << endl;

    // Convert to uppercase
    for (int i = 0; str1[i]; i++)
        str1[i] = toupper(str1[i]);
    cout << "Uppercase str1: " << str1 << endl;

    // Convert to lowercase
    for (int i = 0; str1[i]; i++)
        str1[i] = tolower(str1[i]);
    cout << "Lowercase str1: " << str1 << endl;

    // Find character (first occurrence of 'o')
    char* ch = strchr(str1, 'o');
    if (ch)
        cout << "First occurrence of 'o' in str1: " << (ch - str1) << endl;
    else
        cout << "'o' not found in str1" << endl;

    // Find substring (manual check for "world")
    if (strstr(str1, "world"))
        cout << "Substring 'world' found in str1" << endl;
    else
        cout << "Substring 'world' not found in str1" << endl;

    return 0;
}
/* Expected Output

Length of str1: 10
Copied str1 to str3: HelloWorld
Concatenated str1 + str2: HelloWorldWorld
str1 and str2 are not equal
Substring (first 5 characters): Hello
Uppercase str1: HELLOWORLDWORLD
Lowercase str1: helloworldworld
First occurrence of 'o' in str1: 4
Substring 'world' found in str1
*/
