//Use malloc, calloc, and realloc if working with legacy C code.
//Data from stack would be automatically deallocated when the function exits, but heap allocations persist until free() is called.
//malloc, calloc, realloc, uses heap DS
#include <iostream>
#include <cstdlib> // For malloc, calloc, realloc, free

int main() 
{
    // malloc - Allocates memory without initialization
    int* ptr1 = (int*)malloc(3 * sizeof(int));
    if (!ptr1)
    {
        std::cout << "Memory allocation failed\n";
        return 1;
    }
    ptr1[0] = 10; ptr1[1] = 20; ptr1[2] = 30;
    std::cout << "Malloc: " << ptr1[0] << " " << ptr1[1] << " " << ptr1[2] << "\n";

    // calloc - Allocates memory and initializes with 0
    int* ptr2 = (int*)calloc(3, sizeof(int));
    if (!ptr2) 
    {
        std::cout << "Memory allocation failed\n";
        return 1;
    }
    std::cout << "Calloc: " << ptr2[0] << " " << ptr2[1] << " " << ptr2[2] << "\n";

    // realloc - Resizes previously allocated memory
    ptr1 = (int*)realloc(ptr1, 5 * sizeof(int));
    if (!ptr1) 
    {
        std::cout << "Memory reallocation failed\n";
        return 1;
    }
    ptr1[3] = 40; ptr1[4] = 50;
    std::cout << "Realloc: " << ptr1[0] << " " << ptr1[1] << " " << ptr1[2] << " " << ptr1[3] << " " << ptr1[4] << "\n";

    // free - Deallocates memory
    free(ptr1);
    free(ptr2);

    return 0;
}
