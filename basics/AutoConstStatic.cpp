#include <iostream>

int main() 
{
    // 1) auto: compiler deduces the type
    auto a = 10;            // a is int
    auto b = 2.5f;          // b is float

    // 2) const: read‑only variable
    const int c = 20;
    // c = 30; // error: cannot modify const

    // 3) static: value persists across calls
    static int counter = 0;
    counter++;
    std::cout << "counter = " << counter << "\n";

    return 0;
}
//output
//counter = 1
