# C++ String Handling: `<cstring>` vs `<string>`


## `<cstring>` — C-style Strings

- Inherited from the C programming language.
- Works with character arrays (`char[]` or `char*`).
- Requires manual memory management.
- Strings are null-terminated (`'\0'` at the end).
- Functions operate on raw character data.

###  Common Functions from `<cstring>`:
| Function | Purpose |
|---------|---------|
| `strlen(str)` | Get length of a string |
| `strcpy(dest, src)` | Copy one string to another |
| `strcat(dest, src)` | Concatenate two strings |
| `strcmp(str1, str2)` | Compare two strings |
| `strchr(str, ch)` | Find character in string |
| `strstr(str, substr)` | Find substring in string |

### Limitations:
- No bounds checking
- Fixed size arrays
- Error-prone and not object-oriented

---

##  `<string>` — C++ Style Strings (`std::string`)

- Part of the C++ Standard Library.
- Offers an object-oriented approach to string handling.
- Dynamically resizable.
- Safer and more readable.
- Rich set of built-in functions.

###  Common Operations:
```cpp
#include <string>
#include <iostream>

std::string str = "Hello";
str += " World";              // Concatenate
std::cout << str.length();    // Length
std::string sub = str.substr(0, 5); // Substring
